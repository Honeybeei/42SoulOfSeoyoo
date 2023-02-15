/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:56:20 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:49 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Counts the number of nodes in a list(1st Parameter)

// 1st Parameter :	Head node of the list.
// Return values :	Node count.

int	ft_lstsize(t_list *lst)
{
	t_list	*node_p;
	size_t	count;

	node_p = lst;
	count = 0;
	while (node_p != NULL)
	{
		count++;
		node_p = node_p->next;
	}
	return (count);
}
