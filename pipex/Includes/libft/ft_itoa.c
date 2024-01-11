/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:40:14 by udumas            #+#    #+#             */
/*   Updated: 2023/11/08 22:07:04 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countnumber(int nb, int *count)
{
	long	numb;

	numb = nb;
	if (numb < 0)
	{
		numb *= -1;
		*count = *count + 1;
	}
	if (numb > 9)
		ft_countnumber(numb / 10, &(*count));
	*count = *count + 1;
	return (numb);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		count;
	int		i;
	long	numb;

	count = 0;
	i = 0;
	numb = nb;
	ft_countnumber(nb, &count);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	if (numb < 0)
	{
		str[i++] = '-';
		numb *= -1;
	}
	str[count] = '\0';
	while (i < count--)
	{
		str[count] = numb % 10 + '0';
		numb = numb / 10;
	}
	return (str);
}

// int	main(void)
// {
// 	char *str = ft_itoa(155684);
// 	printf("%s", str);
// }