/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:04:19 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 09:05:50 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	size;
	t_list	*current;

	if (!lst)
		return (0);
	size = 0;
	current = lst;
	while (current->next)
	{
		size++;
		current = current->next;
	}
	return (size);
}
