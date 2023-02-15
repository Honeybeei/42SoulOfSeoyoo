/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:37:05 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/11 13:18:17 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_LIST_H
# define STRING_LIST_H

# include "error_handling.h"
# include "../my_lib/inc/libft.h"

/* ************************************************************************** */

// doubly linked list
typedef struct s_string_node
{
	char					*str_;
	struct s_string_node	*next_;
	struct s_string_node	*prev_;
}	t_str_nd;

typedef struct s_string_list
{
	t_str_nd	*head_;
	t_str_nd	*tail_;
	int			nd_cnt_;
}	t_str_list;

/* ************************************************************************** */

//	string_list_1.c
t_str_nd	*make_str_node(const char *str);
void		*terminate_str_node(t_str_nd *node);
t_str_list	*push_str_nd_to_tail(t_str_list *list, t_str_nd *node);
t_str_nd	*pick_str_nd_from_tail(t_str_list *list);
t_str_list	*pop_str_nd_from_tail(t_str_list *list);

//	string_list_2.c
t_str_list	*make_str_list(void);
void		*terminate_str_list(t_str_list *list);

/* ************************************************************************** */

#endif