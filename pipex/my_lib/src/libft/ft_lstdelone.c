/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:29:16 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:41:52 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Delete(free) the node(1st Parameter) by using del(2nd Parameter)

// 1st Parameter :	The node which it's content(variable) should be deleted.
// 2nd Parameter :	Function to delete the content of the node. 
// Return values :	None. 

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
