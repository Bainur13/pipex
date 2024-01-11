/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:56:37 by udumas            #+#    #+#             */
/*   Updated: 2023/11/23 16:06:01 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checktype(char c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'd')
		return (4);
	else if (c == 'i')
		return (5);
	else if (c == 'u')
		return (6);
	else if (c == 'x')
		return (7);
	else if (c == 'X')
		return (8);
	else if (c == '%')
		return (9);
	else
		return (0);
}

int	ft_checkvalid(const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_checktype(str[i + 1] == 0))
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_zero_one(unsigned long nb, int type, int *count)
{
	if (nb == 0)
		*count = *count + write(1, "(nil)", 5);
	else
	{
		*count = *count + write(1, "0x", 2);
		ft_puthexa(nb, type, &(*count));
	}
}

int	ft_countnumber(long nb)
{
	long	numb;
	int		count;

	if (nb == 0)
		return (1);
	count = 0;
	numb = nb;
	if (numb < 0)
	{
		numb *= -1;
		count = count + 1;
	}
	while (numb > 0)
	{
		numb = numb / 10;
		count = count + 1;
	}
	return (count);
}
