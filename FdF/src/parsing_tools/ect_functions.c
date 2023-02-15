/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ect_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:49:55 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/16 18:53:28 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* ************************************************************************** */

/**
 * @brief Check if map file has '.fdf' extension.
 * 
 * @param file_name 
 * @return t_validity 
 */
void	check_argv(int argc, char **argv)
{
	char	*period_ptr;

	if (argc != 2)
		print_error_exit(ERR_INVALID_ARG);
	period_ptr = ft_strrchr(argv[1], '.');
	if (ft_memcmp(period_ptr, ".fdf", 5) != 0)
		print_error_exit(ERR_INVALID_ARG);
}

/* ************************************************************************** */

/**
 * @brief Terminate ft_split result(string array).
 * 
 * @param str_arr 
 * @return void* 
 */
void	*terminate_ft_split_result(char **str_arr)
{
	int	idx;

	idx = 0;
	while (str_arr[idx] != NULL)
	{
		free(str_arr[idx]);
		idx++;
	}
	free(str_arr);
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Get width data my splitting a row of a map(string with numbers).
 * 
 * @param str_to_split 
 * @return int 
 */
int	get_width(char *str_to_split)
{
	char	**splitted_str;
	int		width_cnt;

	splitted_str = ft_split(str_to_split, ' ');
	width_cnt = 0;
	while (splitted_str[width_cnt] != NULL)
		width_cnt++;
	terminate_ft_split_result(splitted_str);
	return (width_cnt);
}

/* ************************************************************************** */

/**
 * @brief Checks if num_str is a string which has only digit character. A single
 *  '-' sign at the front of string is also ok. 
 * 
 * @param num_str 
 * @return t_validity 
 */
t_validity	check_is_num_str(char *num_str)
{
	int	idx;

	idx = 0;
	if (num_str[idx] == '-')
		idx++;
	while (num_str[idx] != '\0')
	{
		if (ft_isdigit(num_str[idx]))
			idx++;
		else
			return (invalid_);
	}
	return (valid_);
}

/* ************************************************************************** */
