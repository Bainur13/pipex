/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:48:01 by udumas            #+#    #+#             */
/*   Updated: 2023/11/10 14:03:38 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);

void	ft_puthexa(unsigned long nb, int type, int *count);
int		ft_putnbr(int nb);
int		ft_putnbr_nsgd(unsigned int nb);

int		ft_checktype(char c);
int		ft_checkvalid(const char *str);
int		ft_countnumber(long nb);
void	ft_cross(int type, va_list args, int *count);
void	ft_zero_one(unsigned long nb, int type, int *count);

int		ft_printf(const char *str, ...);
int		ft_readstr(const char *str, int *pos);
int		ft_strlenexa(const char *str);
#endif
