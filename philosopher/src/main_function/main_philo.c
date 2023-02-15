/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:10:02 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/06 14:56:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_ptrs	ptrs;

	if (check_arguments(argc, argv) == invalid_)
		return (print_err_return_int(err_invalid_arg_, yes_err_));
	if (initialize_ptrs(&ptrs, argc, argv) == NULL)
		return (termination_protocol(&ptrs, yes_err_));
	if (ptrs.info_.errno_ != no_err_)
		return (termination_protocol(&ptrs, yes_err_));
	activate_philosophers(&ptrs);
	if (ptrs.info_.errno_ != no_err_)
		return (termination_protocol(&ptrs, yes_err_));
	return (termination_protocol(&ptrs, no_err_));
}

/* ************************************************************************** */