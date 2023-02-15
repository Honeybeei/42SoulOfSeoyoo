/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 03:19:59 by seoyoo            #+#    #+#             */
/*   Updated: 2022/10/28 12:41:18 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

/**
 * @brief PIPEX!!!
 * => ./pipex file1 cmd1 cmd2 file2
 * =>  < file1 cmd1 | cmd2 > file2 (shell command)
 * These two must behave exactly same......
 * 
 * @param argc 
 * @param argv 
 * @param envp 
 * @return int 
 */
int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
		print_error_exit("Invalid argumen count...");
	if (pipe(pipe_fd) < 0)
		print_error_exit("Pipe error...");
	pid = fork();
	if (pid < 0)
		print_error_exit("Fork error...");
	else if (pid == 0)
		execute_first_cmd(argv, envp, pipe_fd);
	pid = fork();
	if (pid < 0)
		print_error_exit("Fork error...");
	else if (pid == 0)
		execute_second_cmd(argv, envp, pipe_fd);
	else
		wait(NULL);
	return (0);
}
