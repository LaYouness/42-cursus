/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaarare <ylaarare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:35:09 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/14 21:15:15 by ylaarare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*current;
	t_list	*n_lst_h;

	if (!lst ||!f || !del)
		return (NULL);
	current = lst;
	n_lst_h = NULL;
	while (current)
	{
		if (!current->content)
		{
			ft_lstclear(&n_lst_h, del);
			return (NULL);
		}
		node = ft_lstnew(f(current->content));
		if (!node)
		{
			ft_lstclear(&n_lst_h, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst_h, node);
		current = current->next;
	}
	return (n_lst_h);
}

// int main ()
// {
// 	t_list *head = ft_lstnew("hhhh");
// 	t_list *a = ft_lstnew("fbhet");
// 	//void *str = NULL;
// 	t_list *b = ft_lstnew(NULL);
// 	t_list *c = ft_lstnew("fbhet");
// 	t_list *d = ft_lstnew("iuytre");
// 	ft_lstadd_back(&head, a);
// 	ft_lstadd_back(&head, b);
// 	ft_lstadd_back(&head, c);
// 	ft_lstadd_back(&head, d);
// 	t_list *tmp =  head;
// 	while  (tmp)
// 	{
// 		printf("%s \t",tmp->content);
// 		tmp = tmp->next;
// 	}

// }
