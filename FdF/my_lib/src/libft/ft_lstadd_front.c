/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:48:59 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:53 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Add the node 'new'(2nd Parameter) at the beginning of the list.

// 1st Parameter :	The address of a pointer to the first link of a list. 
// 2nd Parameter :  The address of a pointer to the node to be added to the list
// Return values :	None. 

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
