/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:37:40 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 09:06:41 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*tmp;
	int		non;

	current = *lst;
	non = ft_lstsize(current);
	while (non--)
	{
		tmp = current->next;
		ft_lstdelone(current, del);
		current = tmp;
	}
	free(lst);
}
