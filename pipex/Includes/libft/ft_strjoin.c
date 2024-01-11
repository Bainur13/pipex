/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:40:43 by udumas            #+#    #+#             */
/*   Updated: 2023/11/15 14:13:13 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(const char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2)
				+ 1));
	if (str == NULL)
		return (NULL);
	*str = 0;
	ft_strcpy(s1, str);
	ft_strcpy(s2, (str + ft_strlen((char *)s1)));
	return (str);
}

// int	main(void)
// {
// 	char *s1 = "Mariam";
// 	char *s2 = " la boss";
// 	char *result = ft_strjoin(s1, s2);
// 	printf("%s", result);
// }