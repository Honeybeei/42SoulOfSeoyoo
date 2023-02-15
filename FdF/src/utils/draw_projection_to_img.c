/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projection_to_img.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:09:36 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/16 18:58:16 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static void	draw_horizontal_segments(t_img *img, t_p_map *p_map, int color);
static void	draw_vertical_segments(t_img *img, t_p_map *p_map, int color);

/* ************************************************************************** */

/**
 * @brief Draw projection to img. Draw segments between neighboring coordinates.
 * 
 * @param img 
 * @param p_map 
 * @param color 
 */
void	draw_projection_to_img(t_img *img, t_p_map *p_map, int color)
{
	draw_horizontal_segments(img, p_map, color);
	draw_vertical_segments(img, p_map, color);
}

/* ************************************************************************** */

static void	draw_horizontal_segments(t_img *img, t_p_map *p_map, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_map->height_)
	{
		x = 0;
		while (x < p_map->width_ - 1)
		{
			draw_segment(img, &p_map->matrix_[y][x], &p_map->matrix_[y][x + 1],
				color);
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */

static void	draw_vertical_segments(t_img *img, t_p_map *p_map, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < p_map->width_)
	{
		y = 0;
		while (y < p_map->height_ - 1)
		{
			draw_segment(img, &p_map->matrix_[y][x], &p_map->matrix_[y + 1][x],
				color);
			y++;
		}
		x++;
	}
}

/* ************************************************************************** */