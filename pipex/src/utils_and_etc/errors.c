/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:16:54 by seoyoo            #+#    #+#             */
/*   Updated: 2022/10/28 12:36:36 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

/**
 * @brief Return NULL after printing error.
 * 
 * @param err_msg 
 * @return void* 
 */
void	*print_error_return_null(char *err_msg)
{
	perror(err_msg);
	return (NULL);
}

/**
 * @brief Exit process after pring error. Current process will return 
 * EXIT_FAILURE(1) to parent process.
 * 
 * @param error_message 
 */
void	print_error_exit(char *error_message)
{
	print_error_return_null(error_message);
	exit(EXIT_FAILURE);
}

/**
 * @brief Terminate str_arr(param) -> print error -> exit process by returning 
 * EXIT_FAILURE(1) to its parent process.
 * 
 * @param str_arr 
 * @param error_message 
 */
void	print_error_terminate_str_arr_exit(char **str_arr, char *error_message)
{
	terminate_str_arr(str_arr);
	print_error_exit(error_message);
}
