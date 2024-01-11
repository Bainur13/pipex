/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:40:21 by udumas            #+#    #+#             */
/*   Updated: 2023/11/08 22:07:29 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*chain;

	chain = malloc(sizeof(t_list) * 1);
	if (!chain)
		return (NULL);
	chain->content = content;
	chain->next = NULL;
	return (chain);
}

// int main()
// {
//     char *str = "coucou";

//     t_list *m = ft_lstnew((void *)str);
//     printf("%s\n%s", (char *)m[0].content, (char *)m[0].next);
// }