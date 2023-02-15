/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:09:30 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:54 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Adds the node 'new'(2nd Parameter) at the end of the list. 

// 1st Parameter :	The address of a pointer to the first link of a list. 
// 2nd Parameter :	The address of a pointer to the node to be added to the list
// Return values :	None. 

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
