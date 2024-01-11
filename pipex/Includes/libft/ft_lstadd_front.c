/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:40:17 by udumas            #+#    #+#             */
/*   Updated: 2023/11/08 21:43:03 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
// int main()
// {
//     t_list *new;
//     new = ft_lstnew("uu");
//     t_list *deu;
//     deu = ft_lstnew("oo");
//     ft_lstadd_front(&new, deu);
//     t_list *back;
//     back = ft_lstnew("aa");
//     ft_lstadd_back(&deu, back);
//     t_list *read;
//     read = ft_lstlast(deu);
//      printf("%s", (char *)read->content);
// }
// t_list *initialization(void *lst)
// {
//     t_list *first = malloc(sizeof(*first));
//     t_list *list = malloc(sizeof(*list));
//     /*first = malloc(sizeof(*t_list));
//     list = malloc(sizeof(*t_list));*/s
//     if (!list || !first)
//         return (NULL);
//     list->content = lst;
//     list->next = NULL;
//     first->next = list;

//     return (first);
// }

// void add_end(t_list *premier, void *add)
// {
//     t_list *new;
//     t_list *travel;

//     new = malloc(sizeof(*new));
//     travel = malloc(sizeof(*travel));
//     if (!new || !travel)
//         return ;
//     new->content = add;
//     travel->next = premier->next;
//     while (travel->next != NULL)
//         travel = travel->next;
//     travel->next = new;
//     new->next = NULL;
// }

// /*void add_first(t_list *premier, t_list new)
// {
//     new.next = premier.next;
//     premier.next = new.next;
// }*/

// void display_list(t_list *premier)
// {
//     t_list *travel;

//     travel = premier->next;
//     while (travel != NULL)
//     {
//         printf("%d\n", (int)travel->content);
//         travel = travel->next;
//     }
//     printf("fin");
// }

// int main()
// {
//     int i = 0;
//     t_list *premier = initialization((void *) i);
//     i++;

//     while (i != 3)
//     {
//         add_end(premier, (void *)i);
//         i++;
//     }
//     t_list *ind = malloc(sizeof(ind));
//     ind->content = 25;
//     ind->next = NULL;
//     ft_lstadd_front(&premier, ind);
//     display_list(premier);
// }