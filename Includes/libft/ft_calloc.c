/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:40:12 by udumas            #+#    #+#             */
/*   Updated: 2023/11/08 22:06:32 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if ((nmemb * size < nmemb || size > (nmemb * size)) && size && nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// int main()
// {
//     //int tab[] = {1,2,3,4,5,6,7,8,9,0,1,2,3,5,5,6};
//     int *p; //= tab;
//     p = (int *)ft_calloc(-5, 0);
//     int i = 0;
//     while (i < 100)
//     {
//         printf("%d ", p[i]);
//         i++;
//     }
//     return (0);
// }