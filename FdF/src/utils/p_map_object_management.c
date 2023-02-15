/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_object_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:51:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/16 15:47:50 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* ************************************************************************** */

/**
 * @brief Make new projected map(t_p_map).
 * 
 * @param width 
 * @param height 
 * @return t_p_map* 
 */
t_p_map	*make_new_projection(int width, int height)
{
	t_p_map	*projection;
	int		y;

	projection = malloc(sizeof(t_p_map));
	if (projection == NULL)
		print_error_exit(ERR_MALLOC_FAIL);
	projection->width_ = width;
	projection->height_ = height;
	projection->gap_ = GAP_PRESET_;
	projection->matrix_ = malloc(sizeof(t_p_vec *) * height);
	if (projection->matrix_ == NULL)
		print_error_exit(ERR_MALLOC_FAIL);
	y = 0;
	while (y < height)
	{
		projection->matrix_[y] = malloc(sizeof(t_p_vec) * width);
		if (projection->matrix_[y] == NULL)
			print_error_exit(ERR_MALLOC_FAIL);
		y++;
	}
	return (projection);
}

/* ************************************************************************** */

/**
 * @brief Terminate t_p_map object
 * 
 * @param projection 
 * @return void* 
 */
void	*terminate_projection(t_p_map *projection)
{
	int	y;

	y = 0;
	while (y < projection->height_)
	{
		free(projection->matrix_[y]);
		y++;
	}
	free(projection->matrix_);
	free(projection);
	return (NULL);
}

/* ************************************************************************** */