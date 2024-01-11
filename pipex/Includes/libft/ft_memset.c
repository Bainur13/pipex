/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/06 11:41:20 by udumas            #+#    #+#             */
/*   Updated: 2023/11/06 11:41:20 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	value;

	ptr = (unsigned char *)str;
	value = c;
	i = 0;
	while (i < n)
	{
		ptr[i] = value;
		i++;
	}
	return (str);
}

// int main () {
//    char str[50];

//    strcpy(str,"This is string.h library function");
//    puts(str);

//    memset(str, 300, 7);
//    puts(str);

//    return(0);
// }