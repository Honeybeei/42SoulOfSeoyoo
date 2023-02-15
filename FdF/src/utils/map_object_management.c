/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_object_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 05:07:39 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/16 11:51:07 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static void	*terminate_int_matrix(int **matrix, int height);
static int	**malloc_int_matrix(int width, int height);

/* ************************************************************************** */

/**
 * @brief Make new t_map object. It will return malloced t_map pointer
 * 
 * @return t_map* 
 */
t_map	*make_new_map(void)
{
	t_map	*map;

	map = malloc(sizeof(map));
	if (map == NULL)
		print_error_exit(ERR_MALLOC_FAIL);
	map->width_ = 0;
	map->height_ = 0;
	map->altitude_ = NULL;
	return (map);
}

/* ************************************************************************** */

/**
 * @brief Terminate t_map object. 
 * 
 * @param map 
 * @return void* 
 */
void	*terminate_map(t_map *map)
{
	if (map == NULL)
		print_error_exit(ERR_EMPTY_PTR);
	if (map->altitude_ != NULL)
		terminate_int_matrix(map->altitude_, map->height_);
	free(map);
	return (NULL);
}

/* ************************************************************************** */

static void	*terminate_int_matrix(int **matrix, int height)
{
	int	y;

	y = 0;
	while (y < height)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Set the essential map data(Width, height) and malloc int matrix for 
 * altitude_data_. Returns NULL when error to terminate str_list declared in 
 * upper function. 
 * 
 * @param map 
 * @param width 
 * @param height 
 * @return t_map* 
 */
t_map	*set_essential_map_data(t_map *map)
{
	if (map == NULL)
		print_error_return_null(ERR_EMPTY_PTR);
	map->altitude_ = malloc_int_matrix(map->width_, map->height_);
	if (map->altitude_ == NULL)
		return (NULL);
	return (map);
}

/* ************************************************************************** */

static int	**malloc_int_matrix(int width, int height)
{
	int	**matrix;
	int	idx;

	matrix = malloc(sizeof(int *) * height);
	if (matrix == NULL)
		print_error_return_null(ERR_MALLOC_FAIL);
	idx = 0;
	while (idx < height)
	{
		matrix[idx] = malloc(sizeof(int) * width);
		if (matrix[idx] == NULL)
			print_error_return_null(ERR_MALLOC_FAIL);
		idx++;
	}
	return (matrix);
}

/* ************************************************************************** */