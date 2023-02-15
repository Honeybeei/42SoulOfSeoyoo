/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:47:01 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/16 18:58:43 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* ************************************************************************** */

/**
 * @brief Set the view point. Currently using preset values. 
 * 
 * @param view_point 
 * @return t_3d_vec* 
 */
t_3d_vec	*set_view_point(t_map *map, t_3d_vec *view_point)
{
	t_p_vec	map_center;

	set_3d_vec(view_point, VIEW_POINT_X_, VIEW_POINT_Y_, VIEW_POINT_Z_);
	set_p_vec(&map_center, map->width_ / 2, map->height_ / 2);
	view_point->x_ += map_center.x_;
	view_point->y_ += map_center.y_;
	return (view_point);
}

/* ************************************************************************** */