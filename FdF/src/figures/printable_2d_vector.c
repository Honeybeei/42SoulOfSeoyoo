/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable_2d_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:18:42 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/15 11:22:44 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/my_figure.h"

/* ************************************************************************** */

/**
 * @brief Make two dimensional printable(has int data type) vector. It will 
 * return malloced t_p_vec pointer. 
 * 
 * @param x 
 * @param y 
 * @return t_p_vec* 
 */
t_p_vec	*make_p_vec(int x, int y)
{
	t_p_vec	*vector;

	vector = malloc(sizeof(t_p_vec));
	if (vector == NULL)
		print_error_exit(ERR_MALLOC_FAIL);
	vector->x_ = x;
	vector->y_ = y;
	return (vector);
}

/* ************************************************************************** */

/**
 * @brief Terminate printable vector. 
 * 
 * @param vector 
 * @return void* 
 */
void	*terminate_p_vec(t_p_vec *vector)
{
	if (vector == NULL)
		return (print_error_return_null(ERR_EMPTY_PTR));
	free(vector);
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Set the values of target_vec(param).
 * 
 * @param target_vector 
 * @param x 
 * @param y 
 */
t_p_vec	*set_p_vec(t_p_vec *target, int x, int y)
{
	if (target == NULL)
		return (print_error_return_null(ERR_EMPTY_PTR));
	target->x_ = x;
	target->y_ = y;
	return (target);
}

/* ************************************************************************** */