/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:52:36 by udumas            #+#    #+#             */
/*   Updated: 2023/11/08 22:07:26 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;
	t_list	*cpy;

	if (!f || !del)
		return (NULL);
	newlst = NULL;
	cpy = lst;
	while (cpy != NULL)
	{
		temp = ft_lstnew(f(cpy->content));
		if (!temp)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, temp);
		cpy = cpy->next;
	}
	return (newlst);
}

// int main()
// {
//     int tab[] = {0, 1, 2, 3};
// 	t_list * l =  ft_lstnew(tab[0]);
//     printf("%d", l->content);
// 	for (int i = 1; i < 4; ++i)
//     {
// 		ft_lstadd_back(&l, ft_lstnew(tab[i]));
//         printf("%d\n", (tab[i]));
//     }
//     while (l != NULL)
//     {
//         printf("%d\n", (int)l->content);
//         l = l->next;
//     }
// }