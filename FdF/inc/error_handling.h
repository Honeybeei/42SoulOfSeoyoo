/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:14:01 by seoyoo            #+#    #+#             */
/*   Updated: 2022/11/13 16:41:11 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

/* ************************************************************************** */

# include <errno.h>
# include <stdio.h>  // perror()
# include <stdlib.h>  // EXIT_FAILURE

/* ************************************************************************** */

# define ERR_MALLOC_FAIL "Malloc fail......"
# define ERR_EMPTY_PTR "Pointer is pointing nothing......"
# define ERR_INVALID_ARG "Invalid argment......"
# define ERR_INVALID_FILE "Invalid file......"
# define ERR_OPEN_FAIL "Failed to open file......"

/* ************************************************************************** */

typedef enum e_validity
{
	invalid_ = 0,
	valid_ = 1
}	t_validity;

/* ************************************************************************** */

void		*print_error_return_null(const char *error_msg);
void		print_error_exit(const char *error_msg);
t_validity	print_error_return_invalid(const char *error_msg);

/* ************************************************************************** */

#endif
