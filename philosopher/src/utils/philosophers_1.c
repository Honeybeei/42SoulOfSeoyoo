/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:59:39 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/06 15:31:50 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void		*philosopher_routine(void *philo_);
static t_bool	pick_up_forks(t_philo *philo);
static t_bool	try_pick_up_fork(t_philo *philo, t_dir dir);

/* ************************************************************************** */

/**
 * @brief Activate philosopher thread. Each philosophers(threads) will be 
 * created and philosopher_routine will be executed in each threads. 
 * 
 * @param ptrs_ 
 */
void	activate_philosophers(void *ptrs_)
{
	t_ptrs	*ptrs;
	t_errno	*errno_ptr;
	size_t	idx;

	ptrs = (t_ptrs *)ptrs_;
	errno_ptr = &(ptrs->info_.errno_);
	idx = 0;
	ptrs->info_.start_time_stamp_ = get_time_stamp(errno_ptr, milli_);
	while (idx < ptrs->info_.philo_cnt_)
	{
		if (pthread_create(&(ptrs->philo_arr_[idx].life_), NULL,
				philosopher_routine, &(ptrs->philo_arr_[idx])) != no_err_)
			print_and_mark_err(errno_ptr, err_trd_create_fail_);
		idx++;
	}
	idx = 0;
	while (idx < ptrs->info_.philo_cnt_)
	{
		if (pthread_join(ptrs->philo_arr_[idx].life_, NULL) != no_err_)
			print_and_mark_err(errno_ptr, err_trd_join_fail_);
		idx++;
	}
}

/* ************************************************************************** */

// If starve_to_death occurs(others or it self), NULL will be returned. 
static void	*philosopher_routine(void *philo_)
{
	t_philo	*philo;
	t_errno	*errno_ptr;
	size_t	eat_cnt;

	philo = (t_philo *)philo_;
	errno_ptr = &(philo->info_->errno_);
	eat_cnt = 0;
	philo->starve_start_ = get_time_stamp(errno_ptr, micro_);
	if (philo->id_ % 2 == 0)
		timer_for_actions(philo, philo->info_->time_to_eat_ * PAUSE_CNST / 100);
	while (true)
	{
		if (pick_up_forks(philo) == fail_)
			return (NULL);
		philo->starve_start_ = get_time_stamp(errno_ptr, micro_);
		if (start_eating(philo) == fail_)
			return (NULL);
		eat_cnt++;
		if (philo->info_->eat_cnt_lmt_ > 0
			&& eat_cnt >= philo->info_->eat_cnt_lmt_)
			break ;
		if (start_sleeping(philo) == fail_)
			return (NULL);
	}
	return (philo);
}

/* ************************************************************************** */

/**
 * @brief Philosopher picks up forks. But one fork at a time. "is_available_" 
 * (which will be used to check if the fork is available) flag will be protected
 * by mutex. If philo starve to death, fail_ will be returned. If two forks are 
 * picked successfully, success_ will be returned. 
 * 
 * @param philo 
 * @return t_bool 
 */
static t_bool	pick_up_forks(t_philo *philo)
{
	t_errno	*errno_ptr;
	t_bool	report;
	t_dir	dir;
	int		picked_fork_cnt;

	errno_ptr = &(philo->info_->errno_);
	dir = (philo->id_ + 1) % 2;
	picked_fork_cnt = 0;
	while (true)
	{
		if (*check_starvation(philo, &report) == dead_)
			return (fail_);
		if (try_pick_up_fork(philo, dir) == success_)
		{
			dir = (dir + 1) % 2;
			picked_fork_cnt++;
		}
		if (picked_fork_cnt == 0)
			dir = (dir + 1) % 2;
		else if (picked_fork_cnt == 2)
			break ;
	}
	return (success_);
}

/* ************************************************************************** */

static t_bool	try_pick_up_fork(t_philo *philo, t_dir dir)
{
	t_errno	*errno_ptr;
	t_bool	report;

	errno_ptr = &(philo->info_->errno_);
	if (pthread_mutex_lock(&(philo->fork_[dir]->mutex_)) != no_err_)
		print_and_mark_err(errno_ptr, err_mtx_lock_fail_);
	if (philo->fork_[dir]->is_available_ == available_)
	{
		philo->fork_[dir]->is_available_ = unavailable_;
		print_status_change(philo, STAT_FORK);
		report = success_;
	}
	else
		report = fail_;
	if (pthread_mutex_unlock(&(philo->fork_[dir]->mutex_)) != no_err_)
		print_and_mark_err(errno_ptr, err_mtx_unlock_fail_);
	return (report);
}

/* ************************************************************************** */