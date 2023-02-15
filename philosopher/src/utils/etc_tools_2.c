/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc_tools_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:26:34 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/06 15:06:21 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/* ************************************************************************** */

/**
 * @brief Print the death of philosopher.
 * 
 * @param philo 
 */
void	print_death(t_philo *philo)
{
	if (pthread_mutex_lock(&(philo->info_->print_mutex_)) != no_err_)
		print_and_mark_err(&(philo->info_->errno_), err_mtx_lock_fail_);
	printf("%zu %zu %s\n", get_time_stamp(&(philo->info_->errno_),
			milli_) - philo->info_->start_time_stamp_, philo->id_, STAT_DEAD);
	if (pthread_mutex_unlock(&(philo->info_->print_mutex_)) != no_err_)
		print_and_mark_err(&(philo->info_->errno_), err_mtx_lock_fail_);
	usleep(100);
}

/* ************************************************************************** */