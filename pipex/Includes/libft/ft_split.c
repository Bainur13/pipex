/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:40:36 by udumas            #+#    #+#             */
/*   Updated: 2023/11/15 14:31:34 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c, char ***str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	*str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!(*str))
		return (-1);
	return (0);
}

static void	ft_strncpy(char *src, char *dest, char c)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**str;

	i = -1;
	index = 0;
	if (count_words(s, c, &str) == -1)
		return (NULL);
	while (++i < (int)ft_strlen(s))
	{
		j = i;
		if ((s[i] != c) || ((s[0] != c) && i == 0))
		{
			while (s[j] != c && s[j])
				j++;
			str[index] = (char *)malloc(sizeof(char) * (j - i + 1));
			ft_strncpy((char *)s + i, str[index], c);
			i = j;
			index++;
		}
	}
	str[index] = NULL;
	return (str);
}

// int	main(void)
// {
// 	char *str = "  tripouille  42  ";
// 	char c = ' ';
// 	char **str2 = ft_split(str, ' ');
// 	int i = 0;

// 	while (str2[i] != 0)
// 	{
// 		printf("tab = %s\n", str2[i]);
// 		i++;
// 	}
// }