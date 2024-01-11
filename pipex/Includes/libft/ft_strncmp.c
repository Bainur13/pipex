/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:41:37 by udumas            #+#    #+#             */
/*   Updated: 2023/11/09 10:21:01 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] && n > 0) || (s2[i] && n > 0))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n--;
	}
	return (0);
}

// int main()
// {
//     // char str[] = "la liberte";
//     // char str2[] = "la liberte";

//     // printf("%d\n", ft_strncmp("1234", "1235", 3));
//     // printf("%d\n", strncmp("1234", "1235", 3));

//  	printf("%d", ft_strncmp("test\200", "test\0", 6));
//     return (0);
// }