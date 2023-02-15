/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:32:20 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/05 21:19:54 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	print_err(t_errno my_errno);

/* ************************************************************************** */

/**
 * @brief Print occurring error according to my_errno.
 * 
 * @param my_errno 
 */
static void	print_err(t_errno my_errno)
{
	if (my_errno == err_pointing_null_)
		ft_putstrnl_fd(ERR_POINTING_NULL, STDERR_FILENO);
	else if (my_errno == err_malloc_fail_)
		ft_putstrnl_fd(ERR_MALLOC_FAIL, STDERR_FILENO);
	else if (my_errno == err_invalid_arg_)
		ft_putstrnl_fd(ERR_INVALID_ARG, STDERR_FILENO);
	else if (my_errno == err_trd_create_fail_)
		ft_putstrnl_fd(ERR_TRD_CREATE_FAIL, STDERR_FILENO);
	else if (my_errno == err_trd_join_fail_)
		ft_putstrnl_fd(ERR_TRD_JOIN_FAIL, STDERR_FILENO);
	else if (my_errno == err_trd_detach_fail_)
		ft_putstrnl_fd(ERR_TRD_DETACH_FAIL, STDERR_FILENO);
	else if (my_errno == err_get_time_fail_)
		ft_putstrnl_fd(ERR_GET_TIME_FAIL, STDERR_FILENO);
	else if (my_errno == err_mtx_init_fail_)
		ft_putstrnl_fd(ERR_MTX_INIT_FAIL, STDERR_FILENO);
	else if (my_errno == err_mtx_lock_fail_)
		ft_putstrnl_fd(ERR_MTX_LOCK_FAIL, STDERR_FILENO);
	else if (my_errno == err_mtx_unlock_fail_)
		ft_putstrnl_fd(ERR_MTX_UNLOCK_FAIL, STDERR_FILENO);
	else if (my_errno == err_mtx_destroy_fail_)
		ft_putstrnl_fd(ERR_MTX_DESTROY_FAIL, STDERR_FILENO);
	else
		ft_putstrnl_fd(ERR_UNDEFINED, STDERR_FILENO);
}

/* ************************************************************************** */

/**
 * @brief Save occurred error to "ptrs->info_.errno_" and print error 
 * message
 * 
 * @param errno_ptr 
 * @param occurred_err 
 */
void	print_and_mark_err(t_errno *errno_ptr, t_errno my_errno)
{
	if (PRINT_ERRORS == 1)
		print_err(my_errno);
	*errno_ptr = my_errno;
}

/* ************************************************************************** */

/**
 * @brief Prints error message to STD_ERROR and returns integer. 
 * 
 * @param my_errno 
 * @param i 
 * @return int 
 */
int	print_err_return_int(t_errno my_errno, int num_to_return)
{
	if (PRINT_ERRORS == 1)
		print_err(my_errno);
	return (num_to_return);
}

/* ************************************************************************** */

/**
 * @brief Prints error message to STD_ERROR and returns NULL(void *). 
 * 
 * @param my_errno 
 * @return void* 
 */
void	*print_err_return_null(t_errno my_errno)
{
	if (PRINT_ERRORS == 1)
		print_err(my_errno);
	return (NULL);
}

/* ************************************************************************** */