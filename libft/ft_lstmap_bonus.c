/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:35:09 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/15 08:45:37 by younessla        ###   ########.fr       */
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
