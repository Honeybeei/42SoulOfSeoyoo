/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc_tools_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:26:34 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/06 15:06:13 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/* ************************************************************************** */

/**
 * @brief Destroy all mutexes and free all malloced memory and return exit_code.
 * 
 * @param ptrs 
 * @return int 
 */
int	termination_protocol(t_ptrs *ptrs, int exit_code)
{
	size_t	idx;
	t_errno	*errno_ptr;

	errno_ptr = &(ptrs->info_.errno_);
	if (ptrs == NULL)
		return (print_err_return_int(err_pointing_null_, yes_err_));
	idx = 0;
	while (idx < ptrs->info_.philo_cnt_)
	{
		if (pthread_mutex_destroy(&(ptrs->fork_arr_[idx].mutex_)) != no_err_)
			print_and_mark_err(errno_ptr, err_mtx_destroy_fail_);
		idx++;
	}
	if (pthread_mutex_destroy(&(ptrs->info_.print_mutex_)) != no_err_)
		print_and_mark_err(errno_ptr, err_mtx_destroy_fail_);
	if (pthread_mutex_destroy(&(ptrs->info_.death_flag_mutex_)) != no_err_)
		print_and_mark_err(errno_ptr, err_mtx_destroy_fail_);
	free(ptrs->fork_arr_);
	free(ptrs->philo_arr_);
	return (exit_code);
}

/* ************************************************************************** */

/**
 * @brief Get current time stamp.
 * 
 * @param prefix 
 * @return size_t 
 */
size_t	get_time_stamp(t_errno *errno_ptr, t_pfx prefix)
{
	t_time	now;

	if (gettimeofday(&now, NULL) != no_err_)
	{
		print_and_mark_err(errno_ptr, err_get_time_fail_);
		return (0);
	}
	if (prefix == micro_)
		return (now.tv_sec * 1000000 + now.tv_usec);
	else if (prefix == milli_)
		return (now.tv_sec * 1000 + now.tv_usec / 1000);
	else
		return (0);
}

/* ************************************************************************** */

/**
 * @brief Customized timer to replace usleep(). fail_ will be returned if death
 * occurred while timer is running. If not, success_ will be returned. 
 * 
 * @param philo 
 * @param milli_sec 
 * @return t_bool 
 */
t_bool	timer_for_actions(t_philo *philo, size_t milli_sec)
{
	size_t	start;
	size_t	now;
	t_bool	report;

	start = get_time_stamp(&(philo->info_->errno_), micro_);
	while (true)
	{
		if (*check_starvation(philo, &report) == dead_)
			return (fail_);
		now = get_time_stamp(&(philo->info_->errno_), micro_);
		if (start + milli_sec * 1000 >= now)
			usleep(TIMER_CONSTANT);
		else
			break ;
	}
	return (success_);
}

/* ************************************************************************** */

/**
 * @brief Checks starvation status of current philosopher. Status (alive_ or 
 * dead_) will be marked to report(param). 
 * 
 * @param philo 
 * @param report 
 * @return t_bool* 
 */
t_bool	*check_starvation(t_philo *philo, t_bool *report)
{
	t_errno	*errno_ptr;
	size_t	now;
	t_bool	*death_flag_ptr;

	errno_ptr = &(philo->info_->errno_);
	death_flag_ptr = &(philo->info_->death_flag_);
	if (pthread_mutex_lock(&(philo->info_->death_flag_mutex_)) != no_err_)
		print_and_mark_err(errno_ptr, err_mtx_lock_fail_);
	now = get_time_stamp(errno_ptr, micro_);
	if (*death_flag_ptr == flag_down_)
	{
		if (now > philo->starve_start_ + philo->info_->time_to_die_ * 1000)
		{
			*death_flag_ptr = flag_up_;
			print_death(philo);
			*report = dead_;
		}
		else
			*report = alive_;
	}
	else
		*report = dead_;
	if (pthread_mutex_unlock(&(philo->info_->death_flag_mutex_)) != no_err_)
		print_and_mark_err(errno_ptr, err_mtx_unlock_fail_);
	return (report);
}

/* ************************************************************************** */

/**
 * @brief Print philosopher's status change with time stamp. If death_flag_ is 
 * raised, status change will not be printed and fail_ will be returned. 
 * 
 * @param philo 
 * @param status 
 * @return t_bool 
 */
t_bool	print_status_change(t_philo *philo, char *status)
{
	t_bool	report;

	if (*(check_starvation(philo, &report)) == dead_)
		return (fail_);
	if (pthread_mutex_lock(&(philo->info_->print_mutex_)) != no_err_)
		print_and_mark_err(&(philo->info_->errno_), err_mtx_lock_fail_);
	printf("%zu %zu %s\n", get_time_stamp(&(philo->info_->errno_),
			milli_) - philo->info_->start_time_stamp_, philo->id_, status);
	if (pthread_mutex_unlock(&(philo->info_->print_mutex_)) != no_err_)
		print_and_mark_err(&(philo->info_->errno_), err_mtx_lock_fail_);
	return (success_);
}

/* ************************************************************************** */