/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:37:39 by udumas            #+#    #+#             */
/*   Updated: 2024/01/05 15:29:02 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_cross(int type, va_list args, int *count)
{
	if (type == 1)
		*count = *count + ft_putchar(va_arg(args, int));
	else if (type == 2)
		*count += ft_putstr(va_arg(args, char *));
	else if (type == 7 || type == 8)
		ft_puthexa(va_arg(args, unsigned int), type, &(*count));
	else if (type == 3)
		ft_zero_one(va_arg(args, unsigned long), type, &(*count));
	else if (type == 4 || type == 5)
		*count += ft_putnbr(va_arg(args, int));
	else if (type == 6)
		*count += ft_putnbr_nsgd(va_arg(args, unsigned int));
	else if (type == 9)
		*count += ft_putchar('%');
}

int	ft_readstr(const char *str, int *pos)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			(*pos)++;
			return (ft_checktype(str[(i)]));
		}
		write(1, &(str[i]), 1);
		i++;
		*pos = *pos + 1;
	}
	return (-1);
}

int	ft_strlenexa(const char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i = i + 2;
		else
		{
			i++;
			j++;
		}
	}
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		pos;
	int		type;
	int		count;

	if (ft_checkvalid(str) == 0)
		return (0);
	pos = 0;
	count = 0;
	type = ft_readstr(str, &pos);
	va_start(args, str);
	while (type > 0)
	{
		ft_cross(type, args, &count);
		pos++;
		type = ft_readstr(str + pos, &pos);
	}
	return (count + ft_strlenexa(str));
}
