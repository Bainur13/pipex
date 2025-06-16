/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/06 11:41:29 by udumas            #+#    #+#             */
/*   Updated: 2023/11/06 11:41:29 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*int main()
{
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	printf("%ld", ft_strlen(str));
	return (0);
}*/