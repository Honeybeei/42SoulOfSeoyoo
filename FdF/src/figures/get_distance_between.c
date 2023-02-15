/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance_between.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:26:29 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/16 18:52:39 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/my_figure.h"

/* ************************************************************************** */

/**
 * @brief Get the distance between 3d vec object
 * 
 * @param v1 
 * @param v2 
 * @return double 
 */
double	get_distance_between_3d_vec(t_3d_vec *v1, t_3d_vec *v2)
{
	double	distance_square;
	double	dx;
	double	dy;
	double	dz;

	dx = v1->x_ - v2->x_;
	dy = v1->y_ - v2->y_;
	dz = v1->z_ - v2->z_;
	distance_square = pow(dx, 2) + pow(dy, 2) + pow(dz, 2);
	return (sqrt(distance_square));
}

/* ************************************************************************** */

/**
 * @brief Get the distance from center to 3d vec object
 * 
 * @param v 
 * @return double 
 */
double	get_distance_from_center_to_3d_vec(t_3d_vec *v)
{
	t_3d_vec	center;

	set_3d_vec(&center, 0, 0, 0);
	return (get_distance_between_3d_vec(&center, v));
}

/* ************************************************************************** */