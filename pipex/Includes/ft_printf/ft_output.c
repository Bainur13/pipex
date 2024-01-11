/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:53:44 by udumas            #+#    #+#             */
/*   Updated: 2023/11/10 14:01:21 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	char	alpha;
	long	numb;

	numb = nb;
	if (numb < 0)
	{
		write(1, "-", 1);
		numb = numb * -1;
	}
	if (numb > 9)
		ft_putnbr(numb / 10);
	alpha = numb % 10 + '0';
	write(1, &alpha, 1);
	return (ft_countnumber(nb));
}

int	ft_putnbr_nsgd(unsigned int nb)
{
	char	alpha;

	if (nb > 9)
		ft_putnbr(nb / 10);
	alpha = nb % 10 + '0';
	write(1, &alpha, 1);
	return (ft_countnumber(nb));
}

void	ft_puthexa(unsigned long nb, int type, int *count)
{
	char	alpha;

	if (nb > 15)
		ft_puthexa(nb / 16, type, &(*count));
	nb = nb % 16;
	alpha = "0123456789ABCDEF"[nb];
	if ((type == 7 || type == 3) && (alpha >= 'A' && alpha <= 'Z'))
	{
		alpha = alpha + 32;
		*count = *count + write(1, &alpha, 1);
	}
	else
		*count = *count + write(1, &alpha, 1);
}
