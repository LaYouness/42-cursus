/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:35:09 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 10:20:43 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_node;
	t_list	*current;
	t_list	**n_lst_h;

	if (!lst ||!f || !del)
		return (NULL);
	current = lst;
	n_node = ft_lstnew(f(current->content));
	n_lst_h = &n_node;
	n_node = n_node->next;
	while (current)
	{
		n_node = ft_lstnew(f(current->content));
		if (!n_node->content)
		{
			ft_lstclear(n_lst_h, del);
			return (NULL);
		}
		ft_lstadd_back(n_lst_h, n_node);
		current = current->next;
	}
	return (*n_lst_h);
}
