/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:40:48 by udumas            #+#    #+#             */
/*   Updated: 2023/11/15 14:39:25 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_issep(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen2(char const *str, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i = i - 1;
	while (ft_issep(set, str[i]) == 1 && i > 0)
		i--;
	while (ft_issep(set, str[j]) == 1 && j >= 0)
		j++;
	return (i - j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = -1;
	if (!s1)
		return (NULL);
	if (ft_strlen2(s1, set) < 0)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = 0;
		return (str);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen2(s1, set) + 2);
	if (!str)
		return (NULL);
	while (ft_issep(set, s1[i]) == 1)
		i++;
	while (++j <= (unsigned int)ft_strlen2(s1, set))
		str[j] = s1[i++];
	str[j] = '\0';
	return (str);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char *s1 = "lorem \n ipsum \t dolor \n sit \t amet";
// 	char *sep = " ";
// 	char *str = ft_strtrim("        ", " ");
// 	printf("%s", str);
// 	//printf("%d", strcmp(str, ""));
// }