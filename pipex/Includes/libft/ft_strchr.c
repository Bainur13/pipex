/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:41:23 by udumas            #+#    #+#             */
/*   Updated: 2023/11/08 22:08:28 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	const char	*ind;
	int			i;

	ind = 0;
	i = 0;
	if (c == 0)
		return ((char *)str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
		{
			ind = str + i;
			break ;
		}
		i++;
	}
	return ((char *)ind);
}

// int main()
// {
//     char s[] = "tripouille";
//     char *o = ft_strchr(s, 0);
//     printf("%s", s + ft_strlen(s));
//     return (0);
// }