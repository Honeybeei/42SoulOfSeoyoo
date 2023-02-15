/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:59:39 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/06 15:25:26 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	put_down_fork(t_philo *philo, t_dir dir);

/* ************************************************************************** */

/**
 * @brief Philosopher starts to eat. After eating, it will put down its fork 
 * (by changing is_available_ flag).
 * 
 * @param philo 
 * @return t_bool 
 */
t_bool	start_eating(t_philo *philo)
{
	print_status_change(philo, STAT_EAT);
	if (timer_for_actions(philo, philo->info_->time_to_eat_) == fail_)
		return (fail_);
	put_down_fork(philo, philo->id_ % 2);
	put_down_fork(philo, (philo->id_ + 1) % 2);
	return (success_);
}

/* ************************************************************************** */

static void	put_down_fork(t_philo *philo, t_dir dir)
{
	if (pthread_mutex_lock(&(philo->fork_[dir]->mutex_)) != no_err_)
		print_and_mark_err(&(philo->info_->errno_), err_mtx_lock_fail_);
	philo->fork_[dir]->is_available_ = available_;
	if (pthread_mutex_unlock(&(philo->fork_[dir]->mutex_)) != no_err_)
		print_and_mark_err(&(philo->info_->errno_), err_mtx_unlock_fail_);
}

/* ************************************************************************** */

/**
 * @brief Starts sleeping. After sleeping, philosopher will change its status to
 * thinking. 
 * 
 * @param philo 
 * @return t_bool 
 */
t_bool	start_sleeping(t_philo *philo)
{
	t_errno	*errno_ptr;
	size_t	left_time;

	errno_ptr = &(philo->info_->errno_);
	print_status_change(philo, STAT_SLEEP);
	if (timer_for_actions(philo, philo->info_->time_to_eat_) == fail_)
		return (fail_);
	print_status_change(philo, STAT_THINK);
	left_time = philo->info_->time_to_die_ - philo->info_->time_to_eat_
		- philo->info_->time_to_sleep_;
	if (left_time > SEARCH_FORK_MIN_TIME)
	{
		if (timer_for_actions(philo, left_time - SEARCH_FORK_MIN_TIME) == fail_)
			return (fail_);
	}
	return (success_);
}

/* ************************************************************************** */