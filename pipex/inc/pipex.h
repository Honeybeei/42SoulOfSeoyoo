/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 03:20:29 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/01 22:50:09 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../my_lib/inc/libft.h"
# include <unistd.h>	// fork(), dup2()
# include <stdlib.h>	// EXIT_FAILURE, EXIT_SUCCESS
# include <stdio.h>		// perror()
# include <sys/wait.h>	// wait()
# include <errno.h>		// ERRNO
# include <fcntl.h>		// open()

typedef enum e_pipe_end {
	P_WRITE_ = 1,
	P_READ_ = 0
}	t_p_end;

//	errors.c
void	*print_error_return_null(char *err_msg);
void	print_error_exit(char *error_message);
void	print_error_terminate_str_arr_exit(char **str_arr, char *error_message);

// execute_command.c
void	execute_first_cmd(char **argv, char **envp, int *pipe_fd);
void	execute_second_cmd(char **argv, char **envp, int *pipe_fd);

//	terminate.c
void	*terminate_str_arr(char **str_arr);

#endif