/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_ptrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:57:04 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/05 17:52:18 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_ptrs	*get_argv(t_ptrs *ptrs, int argc, char **argv);
static size_t	simple_atoi_returning_size_t(char *num_str);
static void		initialize_philos(t_ptrs *ptrs);
static void		initialize_forks(t_ptrs *ptrs);

/* ************************************************************************** */

/**
 * @brief Initialize ptrs variable which will carry most of informations in this
 * project. It will return the address of the ptrs when initializing is 
 * completed without malloc fail. If not, it will return NULL to indicate that 
 * there was a malloc fail. Other errors will be recorded to errno.
 * 
 * @param ptrs 
 * @param argc 
 * @param argv 
 * @return t_ptrs* 
 */
t_ptrs	*initialize_ptrs(t_ptrs *ptrs, int argc, char **argv)
{
	if (get_argv(ptrs, argc, argv) == NULL)
		return (NULL);
	ptrs->info_.errno_ = no_err_;
	ptrs->info_.death_flag_ = flag_down_;
	if (pthread_mutex_init(&(ptrs->info_.death_flag_mutex_), NULL) != no_err_)
		print_and_mark_err(&(ptrs->info_.errno_), err_mtx_init_fail_);
	if (pthread_mutex_init(&(ptrs->info_.print_mutex_), NULL) != no_err_)
		print_and_mark_err(&(ptrs->info_.errno_), err_mtx_init_fail_);
	ptrs->info_.start_time_stamp_ = 0;
	ptrs->philo_arr_ = NULL;
	ptrs->fork_arr_ = NULL;
	ptrs->philo_arr_ = malloc(sizeof(t_philo) * ptrs->info_.philo_cnt_);
	if (ptrs->philo_arr_ == NULL)
		return (print_err_return_null(err_malloc_fail_));
	ptrs->fork_arr_ = malloc(sizeof(t_fork) * ptrs->info_.philo_cnt_);
	if (ptrs->fork_arr_ == NULL)
		return (print_err_return_null(err_malloc_fail_));
	initialize_philos(ptrs);
	initialize_forks(ptrs);
	return (ptrs);
}

/* ************************************************************************** */

static t_ptrs	*get_argv(t_ptrs *ptrs, int argc, char **argv)
{
	ptrs->info_.philo_cnt_ = simple_atoi_returning_size_t(argv[1]);
	ptrs->info_.time_to_die_ = simple_atoi_returning_size_t(argv[2]);
	ptrs->info_.time_to_eat_ = simple_atoi_returning_size_t(argv[3]);
	ptrs->info_.time_to_sleep_ = simple_atoi_returning_size_t(argv[4]);
	if (argc == 5)
		ptrs->info_.eat_cnt_lmt_ = 0;
	else
		ptrs->info_.eat_cnt_lmt_ = simple_atoi_returning_size_t(argv[5]);
	if (ptrs->info_.philo_cnt_ > INT32_MAX)
		return (NULL);
	if (ptrs->info_.time_to_die_ > INT32_MAX)
		return (NULL);
	if (ptrs->info_.time_to_eat_ > INT32_MAX)
		return (NULL);
	if (ptrs->info_.time_to_sleep_ > INT32_MAX)
		return (NULL);
	if (ptrs->info_.eat_cnt_lmt_ > INT32_MAX)
		return (NULL);
	return (ptrs);
}

/* ************************************************************************** */

/**
 * @brief Warning : Use this after validity check of num_str(param). Validity 
 * check will be done in main() level. 
 */
static size_t	simple_atoi_returning_size_t(char *num_str)
{
	size_t	result;
	size_t	idx;

	result = 0;
	idx = 0;
	while (num_str[idx] != '\0')
	{
		result *= 10;
		result += num_str[idx] - '0';
		idx++;
	}
	return (result);
}

/* ************************************************************************** */

// Note : b_day_ and life_ will be set in 'give_birth_to_philos()' function.
static void	initialize_philos(t_ptrs *ptrs)
{
	size_t	idx;
	t_philo	*philo_to_set;

	idx = 0;
	while (idx < ptrs->info_.philo_cnt_)
	{
		philo_to_set = &(ptrs->philo_arr_[idx]);
		philo_to_set->id_ = idx + 1;
		philo_to_set->fork_[left_] = &(ptrs->fork_arr_[idx]);
		if (idx + 1 < ptrs->info_.philo_cnt_)
			philo_to_set->fork_[right_] = &(ptrs->fork_arr_[idx + 1]);
		else
			philo_to_set->fork_[right_] = &(ptrs->fork_arr_[0]);
		philo_to_set->starve_start_ = 0;
		philo_to_set->info_ = &(ptrs->info_);
		idx++;
	}
}

/* ************************************************************************** */

static void	initialize_forks(t_ptrs *ptrs)
{
	size_t	idx;
	t_fork	*fork;

	idx = 0;
	while (idx < ptrs->info_.philo_cnt_)
	{
		fork = &(ptrs->fork_arr_[idx]);
		fork->id_ = idx + 1;
		if (pthread_mutex_init(&(fork->mutex_), NULL) != no_err_)
			print_and_mark_err(&(ptrs->info_.errno_), err_mtx_init_fail_);
		fork->is_available_ = available_;
		idx++;
	}
}

/* ************************************************************************** */