/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_dimensional_vector.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:01:36 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/10 18:03:07 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/my_figure.h"

/* ************************************************************************** */

/**
 * @brief Make two dimensional vector. It will return malloced t_2d_vec pointer. 
 * 
 * @param x 
 * @param y 
 * @return t_2d_vec* 
 */
t_2d_vec	*make_2d_vec(double x, double y)
{
	t_2d_vec	*vector;

	vector = malloc(sizeof(t_2d_vec));
	if (vector == NULL)
		print_error_exit(ERR_MALLOC_FAIL);
	vector->x_ = x;
	vector->y_ = y;
	return (vector);
}

/* ************************************************************************** */

/**
 * @brief Terminate two dimensional vector. It will free malloced t_2d_vec 
 * pointer.
 * 
 * @param vector 
 * @return void* 
 */
void	*terminate_2d_vec(t_2d_vec *vector)
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
t_2d_vec	*set_2d_vec(t_2d_vec *target_vec, double x, double y)
{
	if (target_vec == NULL)
		return (print_error_return_null(ERR_EMPTY_PTR));
	target_vec->x_ = x;
	target_vec->y_ = y;
	return (target_vec);
}

/* ************************************************************************** */