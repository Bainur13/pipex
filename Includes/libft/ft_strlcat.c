/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:01:18 by udumas            #+#    #+#             */
/*   Updated: 2023/11/15 14:03:07 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	count;

	if ((dest == NULL || src == NULL) && size == 0)
		return (0);
	i = ft_strlen(dest);
	count = ft_strlen((char *)src);
	j = 0;
	if (size <= i)
		return (count + size);
	else
		count += i;
	while (src[j] != '\0' && (i + 1) < size)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (count);
}
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%zu\n", ft_strlcat(NULL, "", 0));

// }
