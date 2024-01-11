/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:35:26 by udumas            #+#    #+#             */
/*   Updated: 2023/11/08 22:07:12 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	if (*lst == NULL)
		free(*lst);
	else if (del)
	{
		while (temp != NULL)
		{
			*lst = temp->next;
			del(temp->content);
			free(temp);
			temp = *lst;
		}
	}
	lst = NULL;
}
// int main()
// {
//     t_list * l =  ft_lstnew(malloc(1));
// 		 for (int i = 0; i < 10; ++i)
// 			 ft_lstadd_front(&l, ft_lstnew(malloc(1)));
// 		 ft_lstclear(&l, free);
// }