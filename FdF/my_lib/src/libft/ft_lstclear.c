/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:35:26 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:53 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Delete and free the given node(1st Parameter) and every successor of that 
// node, using 'del'(2nd Parameter) and free. Finally, the pointer to the list 
// must be set to NULL;

// 1st Parameter :	Current node and it's successor will be deleted. 
// 2nd Parameter :	Function to delete the content of the node. 
// Return values :	None. 

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node_p;
	t_list	*node_del;

	node_p = *lst;
	while (node_p != NULL)
	{
		node_del = node_p;
		node_p = node_p->next;
		ft_lstdelone(node_del, del);
	}
	*lst = NULL;
}
