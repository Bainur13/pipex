/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:48:35 by udumas            #+#    #+#             */
/*   Updated: 2023/11/08 22:06:27 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = str;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

// int main () {
//    char str[50];

//    strcpy(str,"This is string.h library function");
//    puts(str);

//    bzero(str, 1);
//    puts(str);

//    return(0);
// }