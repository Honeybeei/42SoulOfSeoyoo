/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_node_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:25:20 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/08 01:30:18 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

t_fmt_nd	*make_t_fmt_node(void)
{
	t_fmt_nd	*new_node;

	new_node = malloc(sizeof(t_fmt_nd));
	if (new_node == NULL)
		return (NULL);
	new_node->nstr_ = NULL;
	new_node->next_ = NULL;
	return (new_node);
}

void	*fmt_nd_list_termination_protocol(t_fmt_nd *head)
{
	t_fmt_nd	*del_nd;

	while (head != NULL)
	{
		del_nd = head;
		head = head->next_;
		if (del_nd->nstr_ != NULL)
			terminate_nstr(del_nd->nstr_);
		free(del_nd);
		del_nd = NULL;
	}
	return (NULL);
}

t_fmt_nd	*add_new_node_to_list(t_fmt_nd **head_ptr, t_fmt_nd **tail_ptr)
{
	if (*head_ptr == NULL)
	{
		*head_ptr = make_t_fmt_node();
		if (*head_ptr == NULL)
			return (NULL);
		*tail_ptr = *head_ptr;
	}
	else
	{
		(*tail_ptr)->next_ = make_t_fmt_node();
		if ((*tail_ptr)->next_ == NULL)
			return (fmt_nd_list_termination_protocol(*head_ptr));
		*tail_ptr = (*tail_ptr)->next_;
	}
	return (*head_ptr);
}
