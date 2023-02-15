/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:14:48 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/12 20:44:26 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/error_handling.h"

/* ************************************************************************** */

/**
 * @brief Print error in STD_ERROR and return NULL.
 * 
 * @param error_msg 
 * @return void* 
 */
void	*print_error_return_null(const char *error_msg)
{
	perror(error_msg);
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Print error in STD_ERROR and exit process returning EXIT_FAILURE(1) to
 * parent process. 
 * 
 * @param error_msg 
 */
void	print_error_exit(const char *error_msg)
{
	perror(error_msg);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */

/**
 * @brief Print error in STD_ERROR and return invalid_(t_validity).
 * 
 * @param error_msg 
 * @return t_validity 
 */
t_validity	print_error_return_invalid(const char *error_msg)
{
	perror(error_msg);
	return (invalid_);
}

/* ************************************************************************** */