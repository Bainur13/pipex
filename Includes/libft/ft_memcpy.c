/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:41:15 by udumas            #+#    #+#             */
/*   Updated: 2023/11/15 14:39:11 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr = src;
	unsigned char		*ptr2;
	size_t				i;

	ptr2 = dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		ptr2[i] = ptr[i];
		i++;
	}
	return (dest);
}

// int main() {

//     int * array  = NULL;
//     int * copy = NULL;
//     int length = sizeof( int ) * 5;

//     /* Memory allocation and copy */
//     ft_memcpy( copy, array, length );

//     /* Display the copied values */
//     for( length=0; length<5; length++ ) {
//         printf( "%d ", copy[ length ] );
//     }
//     printf( "\n" );

//     return (EXIT_SUCCESS);
// }