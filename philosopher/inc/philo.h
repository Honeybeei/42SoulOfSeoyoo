/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:06:28 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/06 15:35:46 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ************************************************************************** */

// including headers
# include <string.h>	// memset()
# include <stdio.h>		// printf()
# include <stdlib.h>    // free(), malloc()
# include <unistd.h>    // write(), usleep()
# include <sys/time.h>  // gettimeofday()
# include <pthread.h>	// pthread_create() and other pthread functions
# include <stdbool.h>	// true

/* ************************************************************************** */

// define constants
# define TIMER_CONSTANT			10
# define PRINT_ERRORS			1
# define SEARCH_FORK_MIN_TIME	10
# define PAUSE_CNST				20

// define status message
# define STAT_FORK		"has taken a fork"
# define STAT_EAT		"is eating"
# define STAT_SLEEP		"is sleeping"
# define STAT_THINK		"is thinking"
# define STAT_DEAD		"died"

/* ************************************************************************** */

// Indicative enums

typedef enum e_my_boolean
{
	valid_ = 0,
	invalid_,
	available_ = 0,
	unavailable_,
	flag_down_ = 0,
	flag_up_,
	alive_ = 0,
	dead_,
	success_ = 0,
	fail_
}	t_bool;

typedef enum e_directions
{
	left_ = 0,
	right_
}	t_dir;

// NOTE : Prefix used in time_stamp will be micro_
typedef enum e_metric_prefixes
{
	micro_ = -6,
	milli_ = -3
}	t_pfx;

/* ************************************************************************** */

// Error management

/**
 * About Error Management
 * 
 * In this project, we will use e_my_errno to handle errors. 
 * We can't use exit() function. Therefore, we can't just terminate the process
 * when the error occurs. So Errors will be treated like this. 
 * 1.	ARGV error will be handled first. Because no malloc and mutex_init 
 * 		happened before ARGV check, termination protocol will not be executed.
 * 		Only error message will be printed to STD_ERROR and return 1 to parent 
 * 		process. 
 * 2.	Except ARGV error
 * 		2-1.	If function execution fails, error will be marked to 
 * 				"ptrs->info_.errno_". If malloc fail, process will not be 
 * 				continued and will call termination protocol. 
 * 		2-2.	Error message will be printed immediately. But it will go on.
 * 		2-3.	Termination protocol will be executed only at the main() 
 * 				function level if errno is marked.
 */

// my_errno
typedef enum e_my_errno
{
	no_err_ = 0,
	yes_err_,
	err_pointing_null_ = 100,
	err_malloc_fail_,
	err_invalid_arg_,
	err_trd_create_fail_,
	err_trd_join_fail_,
	err_trd_detach_fail_,
	err_get_time_fail_,
	err_mtx_init_fail_,
	err_mtx_lock_fail_,
	err_mtx_unlock_fail_,
	err_mtx_destroy_fail_,
	err_undefined_ = 999
}	t_errno;

// define error messages
# define ERR_POINTING_NULL		"Target pointing nothing......"
# define ERR_MALLOC_FAIL		"Malloc fail......"
# define ERR_INVALID_ARG		"Invalid arguments......"
# define ERR_TRD_CREATE_FAIL	"Thread creation fail......"
# define ERR_TRD_JOIN_FAIL		"Thread join fail......"
# define ERR_TRD_DETACH_FAIL	"Thread detach fail......"
# define ERR_GET_TIME_FAIL		"Time getting fail......"
# define ERR_MTX_INIT_FAIL		"Mutex init fail......"
# define ERR_MTX_LOCK_FAIL		"Mutex lock fail......"
# define ERR_MTX_UNLOCK_FAIL	"Mutex unlock fail......"
# define ERR_MTX_DESTROY_FAIL	"Mutex destroy fail......"
# define ERR_UNDEFINED			"Undefined error occurred......"

/* ************************************************************************** */

// Structs for this projects

typedef struct timeval	t_time;

typedef struct s_philo_info
{
	size_t			philo_cnt_;
	size_t			time_to_die_;
	size_t			time_to_eat_;
	size_t			time_to_sleep_;
	size_t			eat_cnt_lmt_;
	t_errno			errno_;
	t_bool			death_flag_;
	pthread_mutex_t	death_flag_mutex_;
	pthread_mutex_t	print_mutex_;
	size_t			start_time_stamp_;
}	t_info;

typedef struct s_fork
{
	size_t			id_;	
	pthread_mutex_t	mutex_;
	t_bool			is_available_;
}	t_fork;

// 'id_' starts from 1 (only for visualization, nothing more...)
typedef struct s_philosopher
{
	size_t		id_;
	t_fork		*fork_[2];
	pthread_t	life_;
	size_t		starve_start_;
	t_info		*info_;
}	t_philo;

typedef struct s_philo_pointers
{
	t_info		info_;
	t_philo		*philo_arr_;
	t_fork		*fork_arr_;
}	t_ptrs;

/* ************************************************************************** */

// UTILS

// check_arguments.c
t_bool	check_arguments(int argc, char **argv);

// errors.c
void	print_and_mark_err(t_errno *errno_ptr, t_errno occurred_err);
int		print_err_return_int(t_errno my_errno, int num_to_return);
void	*print_err_return_null(t_errno my_errno);

// etc_tools_1.c
int		termination_protocol(t_ptrs *ptrs, int exit_code);
size_t	get_time_stamp(t_errno *errno_ptr, t_pfx prefix);
t_bool	timer_for_actions(t_philo *philo, size_t milli_sec);
t_bool	*check_starvation(t_philo *philo, t_bool *report);
t_bool	print_status_change(t_philo *philo, char *status);

// etc_tools_2.c
void	print_death(t_philo *philo);

// initialize_ptrs.c
t_ptrs	*initialize_ptrs(t_ptrs *ptrs, int argc, char **argv);

// libft_functions.c
int		ft_putstrnl_fd(const char *str, int fd);

// philosophers_1.c
void	activate_philosophers(void *ptrs_);

// philosophers_2.c
t_bool	start_eating(t_philo *philo);
t_bool	start_sleeping(t_philo *philo);

/* ************************************************************************** */

#endif