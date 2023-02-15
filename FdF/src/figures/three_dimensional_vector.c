/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_dimensional_vector.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:31:45 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/13 21:26:18 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/my_figure.h"

/* ************************************************************************** */

/**
 * @brief Make three dimensional vector. It will return malloced t_3d_vec 
 * pointer. 
 * 
 * @param x 
 * @param y 
 * @param z 
 * @return t_3d_vec* 
 */
t_3d_vec	*make_3d_vec(double x, double y, double z)
{
	t_3d_vec	*vector;

	vector = malloc(sizeof(t_3d_vec));
	if (vector == NULL)
		print_error_exit(ERR_MALLOC_FAIL);
	vector->x_ = x;
	vector->y_ = y;
	vector->z_ = z;
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
void	*terminate_3d_vec(t_3d_vec *vector)
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
 * @param target_vec 
 * @param x 
 * @param y 
 * @param z 
 * @return t_3d_vec* 
 */
t_3d_vec	*set_3d_vec(t_3d_vec *target_vec, double x, double y, double z)
{
	if (target_vec == NULL)
		return (print_error_return_null(ERR_EMPTY_PTR));
	target_vec->x_ = x;
	target_vec->y_ = y;
	target_vec->z_ = z;
	return (target_vec);
}

/* ************************************************************************** */