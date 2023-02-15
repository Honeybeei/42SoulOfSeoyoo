/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:03:39 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:51 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Returns the last Node of the list.

// 1st Parameter :	The beginning node if the list
// Return values :	Last node of the list. 

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node_p;

	if (lst == NULL)
		return (NULL);
	node_p = lst;
	while (node_p->next != NULL)
		node_p = node_p->next;
	return (node_p);
}
