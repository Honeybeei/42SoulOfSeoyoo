/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:01:46 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/17 16:30:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static t_str_list	*convert_map_to_str_list(const char *file_name);
static void			err_protocol(char *err_msg, t_str_list *list, t_map *map);
static void			put_altitude_data(t_map *map, t_str_list *str_list);

/* ************************************************************************** */

// read map data -> ... -> return map pointer with complete altitude_

/**
 * @brief Get the map data object.
 * If error occurs, print error message in std_error and exit. 
 * 
 * @param file_name 
 * @return t_map* 
 */
t_map	*get_map_data(t_map *map, const char *file_name)
{
	t_str_list	*str_list;

	str_list = convert_map_to_str_list(file_name);
	map->width_ = get_width(str_list->head_->str_);
	map->height_ = str_list->nd_cnt_;
	if (set_essential_map_data(map) == NULL)
		err_protocol(NULL, str_list, map);
	put_altitude_data(map, str_list);
	terminate_str_list(str_list);
	return (map);
}

/* ************************************************************************** */

// If error, just exit
static t_str_list	*convert_map_to_str_list(const char *file_name)
{
	int			file_fd;
	t_str_list	*str_list;
	char		*gnl_result;
	char		*trimmed_gnl_result;

	file_fd = open(file_name, O_RDONLY);
	if (file_fd < 0)
		print_error_exit(ERR_OPEN_FAIL);
	str_list = make_str_list();
	while (true)
	{
		gnl_result = get_next_line(file_fd);
		if (gnl_result == NULL)
			break ;
		trimmed_gnl_result = ft_strtrim(gnl_result, "\n");
		free(gnl_result);
		push_str_nd_to_tail(str_list, make_str_node(trimmed_gnl_result));
		free(trimmed_gnl_result);
	}
	close(file_fd);
	return (str_list);
}

/* ************************************************************************** */

static void	err_protocol(char *err_msg, t_str_list *str_list, t_map *map)
{
	terminate_str_list(str_list);
	terminate_map(map);
	print_error_exit(err_msg);
}

/* ************************************************************************** */

// Return NULL when error. Do not exit
static void	put_altitude_data(t_map *map, t_str_list *str_list)
{
	int			x_idx;
	int			y_idx;
	t_str_nd	*nd_ptr;
	char		**splitted_str;

	nd_ptr = str_list->head_;
	y_idx = 0;
	while (y_idx < str_list->nd_cnt_)
	{
		if (map->width_ != get_width(nd_ptr->str_))
			err_protocol(ERR_INVALID_DATA_WIDTH, str_list, map);
		splitted_str = ft_split(nd_ptr->str_, ' ');
		x_idx = 0;
		while (x_idx < map->width_)
		{
			if (check_is_num_str(splitted_str[x_idx]) == invalid_)
				err_protocol(ERR_INVALID_DATA_ALTITUDE, str_list, map);
			map->altitude_[y_idx][x_idx] = ft_atoi(splitted_str[x_idx]);
			x_idx++;
		}
		terminate_ft_split_result(splitted_str);
		y_idx++;
		nd_ptr = nd_ptr->next_;
	}
}

/* ************************************************************************** */
