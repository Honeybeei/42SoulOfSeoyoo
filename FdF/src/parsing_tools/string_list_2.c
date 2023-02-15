/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:59:18 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/10 22:34:43 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/string_list.h"

/* ************************************************************************** */

/**
 * @brief Make singly linked list which saves (char *) in each node. 
 * 
 * @return t_str_list* 
 */
t_str_list	*make_str_list(void)
{
	t_str_list	*list;

	list = malloc(sizeof(t_str_list));
	if (list == NULL)
		print_error_exit(ERR_MALLOC_FAIL);
	list->head_ = NULL;
	list->tail_ = NULL;
	list->nd_cnt_ = 0;
	return (list);
}

/* ************************************************************************** */

/**
 * @brief Pops all node in list and free list. 
 * 
 * @param list 
 * @return void* 
 */
void	*terminate_str_list(t_str_list *list)
{
	if (list == NULL)
		return (print_error_return_null(ERR_EMPTY_PTR));
	while (list->nd_cnt_ > 0)
		pop_str_nd_from_tail(list);
	free(list);
	return (NULL);
}

/* ************************************************************************** */
