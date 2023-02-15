/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:30:18 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/05 17:26:38 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_bool	check_vld_positive_num(char *num_str);

/* ************************************************************************** */

/**
 * @brief Checks arguments. Following conditions will be considered as an 
 * argument error. 
 * 1. If the number of give arguments is not 4 or 5.
 * 2. If given arguments are not positive integers or zero.
 * 
 * @param argc 
 * @param argv 
 * @return t_bool 
 */
t_bool	check_arguments(int argc, char **argv)
{
	int	idx;

	if (argc != 5 && argc != 6)
		return (invalid_);
	idx = 1;
	while (idx < argc)
	{
		if (check_vld_positive_num(argv[idx]) == invalid_)
			return (invalid_);
		idx++;
	}
	return (valid_);
}

/* ************************************************************************** */

static t_bool	check_vld_positive_num(char *num_str)
{
	size_t	idx;

	if (num_str == NULL || num_str[0] == '\0')
		return (invalid_);
	if (num_str[0] == '0')
		return (invalid_);
	idx = 0;
	while (num_str[idx] != '\0')
	{
		if (num_str[idx] < '0' || '9' < num_str[idx])
			return (invalid_);
		idx++;
	}
	return (valid_);
}

/* ************************************************************************** */