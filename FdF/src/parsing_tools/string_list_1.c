/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_list_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:36:19 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/13 16:30:20 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/string_list.h"

/* ************************************************************************** */

/**
 * @brief Make string node. String in node is duplicated(malloced) string.
 * 
 * @param str 
 * @return t_str_nd* 
 */
t_str_nd	*make_str_node(const char *str)
{
	t_str_nd	*node;

	node = malloc(sizeof(t_str_nd));
	if (node == NULL)
		print_error_exit(ERR_MALLOC_FAIL);
	if (str == NULL)
		node->str_ = NULL;
	else
		node->str_ = ft_strdup(str);
	node->next_ = NULL;
	node->prev_ = NULL;
	return (node);
}

/* ************************************************************************** */

/**
 * @brief Free string in node and disconnect if it is sill connected.
 * 
 * @param node 
 * @return void* 
 */
void	*terminate_str_node(t_str_nd *node)
{
	if (node == NULL)
		return (print_error_return_null(ERR_EMPTY_PTR));
	free(node->str_);
	node->next_ = NULL;
	node->prev_ = NULL;
	free(node);
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Push string node to the tail of string list. It will return NULL when 
 * one of parameter is NULL or given node(parameter) is still connected to other
 * node. 
 * 
 * @param list 
 * @param node 
 * @return t_str_list* 
 */
t_str_list	*push_str_nd_to_tail(t_str_list *list, t_str_nd *node)
{
	if (list == NULL || node == NULL)
		return (print_error_return_null(ERR_EMPTY_PTR));
	if (node->next_ != NULL || node->prev_ != NULL)
		return (print_error_return_null("Connection still exits......"));
	if (list->nd_cnt_ == 0)
	{
		list->head_ = node;
		list->tail_ = node;
	}
	else
	{
		list->tail_->next_ = node;
		node->prev_ = list->tail_;
		list->tail_ = list->tail_->next_;
	}
	list->nd_cnt_++;
	return (list);
}

/* ************************************************************************** */

/**
 * @brief Pick and return string node from the tail of the list(parameter). It
 * will return NULL if list(parameter) is NULL or there are no node to pick. 
 * 
 * @param list 
 * @return t_str_nd* 
 */
t_str_nd	*pick_str_nd_from_tail(t_str_list *list)
{
	t_str_nd	*picked_node;

	if (list == NULL)
		return (print_error_return_null(ERR_EMPTY_PTR));
	if (list->nd_cnt_ == 0)
		return (print_error_return_null("Not enough nodes to pick......"));
	picked_node = list->tail_;
	if (list->nd_cnt_ == 1)
	{
		list->head_ = NULL;
		list->tail_ = NULL;
	}
	else
	{
		list->tail_ = picked_node->prev_;
		picked_node->prev_ = NULL;
		list->tail_->next_ = NULL;
	}
	list->nd_cnt_--;
	return (picked_node);
}

/* ************************************************************************** */

/**
 * @brief Pop string node from the tail of the list. It will return NULL if 
 * popping process is not successful. 
 * 
 * @param list 
 * @return t_str_list* 
 */
t_str_list	*pop_str_nd_from_tail(t_str_list *list)
{
	t_str_nd	*node_to_pop;

	node_to_pop = pick_str_nd_from_tail(list);
	if (node_to_pop == NULL)
		return (NULL);
	terminate_str_node(node_to_pop);
	return (list);
}

/* ************************************************************************** */