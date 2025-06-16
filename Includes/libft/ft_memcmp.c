/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:41:11 by udumas            #+#    #+#             */
/*   Updated: 2023/11/08 22:07:41 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	const unsigned char	*str = s1;
	const unsigned char	*str2 = s2;
	size_t				i;

	i = 0;
	while (i < size)
	{
		if (str[i] - str2[i] != 0)
			return (str[i] - str2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char sCpy[] = {-128, 0, 127, 0};
// 	char s[] = {-128, 0, 127, 0};
// 	int i = ft_memcmp(s, sCpy, 4);
// 	printf("%d", i);
// 	return (0);
// }