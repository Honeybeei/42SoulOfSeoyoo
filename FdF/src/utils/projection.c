/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:19:10 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/16 13:28:28 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static t_p_map	*project_map(t_map *map, t_p_map *p_map, t_3d_vec *view_point);
static void		get_edge(int *edge, t_p_map *p_map);
static void		isometric(t_3d_vec *src, t_p_vec *dst, t_3d_vec *view_p);
static void		relocate_projection(t_p_map *p_map);

/* ************************************************************************** */

/**
 * @brief Get the projection result. Reduce gap until the img fits in to the 
 * window. 
 * 
 * @param map 
 * @param p_map 
 * @param view_p 
 */
void	get_projection_result(t_map *map, t_p_map *p_map, t_3d_vec *view_p)
{
	int	max_width;
	int	max_height;

	max_width = W_W_ - W_PADDING_;
	max_height = W_H_ - W_PADDING_;
	while (true)
	{
		project_map(map, p_map, view_p);
		if (p_map->img_width_ < max_width && p_map->img_height < max_height)
			break ;
		else
			p_map->gap_--;
	}
	relocate_projection(p_map);
}

/* ************************************************************************** */

/**
 * @brief Project each coordinate to screen. In this project, isometric 
 * projection will be used. 
 * 
 * @param map 
 * @param p_map 
 * @param view_p 
 * @return t_p_map* 
 */
static t_p_map	*project_map(t_map *map, t_p_map *p_map, t_3d_vec *view_p)
{
	int			x;
	int			y;
	t_3d_vec	temp;
	int			edge[4];

	if (map == NULL || p_map == NULL || view_p == NULL)
		print_error_exit(ERR_EMPTY_PTR);
	y = 0;
	while (y < map->height_)
	{
		x = 0;
		while (x < map->width_)
		{
			temp.x_ = x * p_map->gap_;
			temp.y_ = y * p_map->gap_;
			temp.z_ = map->altitude_[y][x] * p_map->gap_ / ALTITUDE_CONST;
			isometric(&temp, &p_map->matrix_[y][x], view_p);
			x++;
		}
		y++;
	}
	get_edge(edge, p_map);
	p_map->img_width_ = edge[right_] - edge[left_];
	p_map->img_height = edge[top_] - edge[bottom_];
	return (p_map);
}

/* ************************************************************************** */

static void	isometric(t_3d_vec *src, t_p_vec *dst, t_3d_vec *view_p)
{
	if (src == NULL || dst == NULL || view_p == NULL)
		print_error_exit(ERR_EMPTY_PTR);
	dst->x_ = floor((src->x_ - src->y_) * cos(M_PI / 6) + 0.5);
	dst->y_ = floor((src->x_ + src->y_) * sin(M_PI / 6) - src->z_ + 0.5);
}

/* ************************************************************************** */

static void	get_edge(int *edge, t_p_map *p_map)
{
	int	x;
	int	y;

	edge[left_] = p_map->matrix_[0][0].x_;
	edge[right_] = p_map->matrix_[0][0].x_;
	edge[top_] = p_map->matrix_[0][0].y_;
	edge[bottom_] = p_map->matrix_[0][0].y_;
	y = 0;
	while (y < p_map->height_)
	{
		x = 0;
		while (x < p_map->width_)
		{
			if (p_map->matrix_[y][x].x_ > edge[right_])
				edge[right_] = p_map->matrix_[y][x].x_;
			else if (p_map->matrix_[y][x].x_ < edge[left_])
				edge[left_] = p_map->matrix_[y][x].x_;
			if (p_map->matrix_[y][x].y_ > edge[top_])
				edge[top_] = p_map->matrix_[y][x].y_;
			else if (p_map->matrix_[y][x].y_ < edge[bottom_])
				edge[bottom_] = p_map->matrix_[y][x].y_;
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */

static void	relocate_projection(t_p_map *p_map)
{
	int	edge[4];
	int	x;
	int	y;

	get_edge(edge, p_map);
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
