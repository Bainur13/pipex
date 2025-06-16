/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:41:08 by udumas            #+#    #+#             */
/*   Updated: 2023/11/08 22:07:37 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int c, size_t size)
{
	const unsigned char	*ptr = (const unsigned char *)mem;
	size_t				i;

	i = 0;
	while (size > 0)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)ptr + i);
		i++;
		size--;
	}
	return (0);
}

//  int	main(void)
//  {
//  	char s[] = {'0', '1', 50 ,'3' ,'4' ,'5'};
//  	void *str = ft_memchr(s, '2', 3);
//  	printf("%s", (char *)str);
//  	return (0);
//  }