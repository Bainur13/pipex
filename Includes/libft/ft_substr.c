/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:40:52 by udumas            #+#    #+#             */
/*   Updated: 2023/11/15 14:16:33 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str = malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	if (ft_strlen(s + start) <= len)
		str = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (++i < len && s[start] != '\0')
	{
		str[i] = s[start];
		start++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char *s = "1234567890";
// 	char *a = ft_substr("tripouille", 1, 1);
// 	printf("%s", a);
// }