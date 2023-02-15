/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_dimensional_segment.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:30:37 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/13 16:34:46 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/my_figure.h"

/* ************************************************************************** */

/**
 * @brief Make two dimensional segment. It will return malloced t_2d_seg 
 * pointer. Vectors given as parameters will not be terminated.
 * 
 * @param a 
 * @param b 
 * @return t_2d_seg* 
 */
t_2d_seg	*make_2d_seg(t_2d_vec *a, t_2d_vec *b)
{
	t_2d_seg	*segment;

	segment = malloc(sizeof(t_2d_seg));
	if (segment == NULL)
		print_error_exit(ERR_MALLOC_FAIL);
	set_2d_vec(&(segment->a_), a->x_, a->y_);
	set_2d_vec(&(segment->b_), b->x_, b->y_);
	return (segment);
}

/* ************************************************************************** */

/**
 * @brief Terminate two dimensional segment. It will free malloced t_2d_seg 
 * pointer.
 * 
 * @param segment 
 * @return void* 
 */
void	*terminate_2d_seg(t_2d_seg *segment)
{
	if (segment == NULL)
		return (print_error_return_null(ERR_EMPTY_PTR));
	free(segment);
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Set the values of target_seg(param). Vectors(parameter 2 and 3) will 
 * not be terminated in this function. 
 * 
 * @param target_seg 
 * @param a 
 * @param b 
 * @return t_2d_seg* 
 */
t_2d_seg	*set_2d_seg(t_2d_seg *target_seg, t_2d_vec *a, t_2d_vec *b)
{
	if (target_seg == NULL || a == NULL || b == NULL)
		return (print_error_return_null(ERR_EMPTY_PTR));
	set_2d_vec(&target_seg->a_, a->x_, a->y_);
	set_2d_vec(&target_seg->b_, b->x_, b->y_);
	return (target_seg);
}

/* ************************************************************************** */