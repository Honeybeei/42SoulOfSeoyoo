/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:33:00 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:51 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Iterates the list 'lst'(1st Parameter) and applies the function 'f'(2nd 
// Parameter) on the content of each node.

// 1st Parameter :	The address of a pointer to a node.
// 2nd Parameter :	The address of the function used to iterate on the list. 
// Return values :	None. 

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node_p;

	node_p = lst;
	while (node_p != NULL)
	{
		f(node_p->content);
		node_p = node_p->next;
	}
}
