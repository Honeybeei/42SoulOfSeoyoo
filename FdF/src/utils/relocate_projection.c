/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relocate_projection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:19:01 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/16 18:26:29 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* ************************************************************************** */

/**
 * @brief Set p_map->img_width & img_height. Move map to center of image.
 * WARNING : This function will only be used in mandatory part. If view point 
 * changes, moving map to center will be approached in different way. 
 * 
 * @param p_map 
 */
void	relocate_projection(t_p_map *p_map)
{
	int	edge[4];
	int	x;
	int	y;

	y = 0;
	while (y < p_map->height_)
	{
		x = 0;
		while (x < p_map->width_)
		{
			p_map->matrix_[y][x].x_ -= edge[left_];
			p_map->matrix_[y][x].y_ -= edge[bottom_];
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */