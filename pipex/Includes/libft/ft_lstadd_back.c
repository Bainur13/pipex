/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:45:43 by udumas            #+#    #+#             */
/*   Updated: 2023/11/08 21:39:42 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*travel;

	if (lst == NULL)
		return ;
	travel = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (travel->next != NULL)
			travel = travel->next;
		travel->next = new;
	}
}

// int main()
// {
//     t_list * l =  NULL; t_list * l2 =  NULL;
// 	ft_lstadd_back(&l, ft_lstnew((void*)1));
// }