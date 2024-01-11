/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:40:30 by udumas            #+#    #+#             */
/*   Updated: 2023/11/08 22:08:11 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	temp;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	temp = nb % 10 + '0';
	write(fd, &temp, 1);
}

// int	main(void)
// {
// 	int fd = open("m.txt", O_WRONLY | O_APPEND);

// 	ft_putnbr_fd(0, fd);

// 	close(fd);
// 	return (0);
// }