/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:41:43 by udumas            #+#    #+#             */
/*   Updated: 2023/11/15 14:39:20 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = 0;
	if ((big == NULL || little == NULL) && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)(big));
	while (big[i] && len > 0)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] != '\0')
		{
			j++;
		}
		if (little[j] == '\0' && len >= j)
			return ((char *)(big + i));
		i++;
		len--;
	}
	return (str);
}

// int main()
// {
//     char a[30]= "aaabcabcd";
//     char b[] = "zizi";

//     printf("%s", ft_strnstr(a, "abcd", 9));
//     return (0);
// }