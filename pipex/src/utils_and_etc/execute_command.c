/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:52:32 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/01 22:50:08 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

static char	*get_cmd_path(char *cmd_str, char **envp);
static char	**join_string_to_strings(char **str_arr, char *str_to_join);
static int	count_strs(char **str_arr);

/**
 * @brief Execute first command in child process. 
 * 
 * @param argv 
 * @param envp 
 * @param pipe_fd 
 */
void	execute_first_cmd(char **argv, char **envp, int *pipe_fd)
{
	int		infile_fd;
	char	*cmd_path;
	char	**cmd_args;

	close(pipe_fd[P_READ_]);
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd < 0)
		print_error_exit("Open() error...");
	if (dup2(infile_fd, STDIN_FILENO) < 0)
		print_error_exit("Dup2() error...");
	close(infile_fd);
	if (dup2(pipe_fd[P_WRITE_], STDOUT_FILENO) < 0)
		print_error_exit("Dup2() error...");
	close(pipe_fd[P_WRITE_]);
	cmd_args = ft_split(argv[2], ' ');
	cmd_path = get_cmd_path(cmd_args[0], envp);
	if (cmd_path == NULL)
		print_error_exit("cmd path error...");
	if (execve(cmd_path, cmd_args, envp) < 0)
	{
		if (cmd_path != NULL)
			free(cmd_path);
		print_error_terminate_str_arr_exit(cmd_args, "Execve fail...");
	}
}

/**
 * @brief Execute second command in child process. 
 * 
 * @param argv 
 * @param envp 
 * @param pipe_fd 
 */
void	execute_second_cmd(char **argv, char **envp, int *pipe_fd)
{
	int		outfile_fd;
	char	*cmd_path;
	char	**cmd_args;

	close(pipe_fd[P_WRITE_]);
	outfile_fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile_fd < 0)
		print_error_exit("Open() error...");
	if (dup2(outfile_fd, STDOUT_FILENO) < 0)
		print_error_exit("Dup2() error...");
	close(outfile_fd);
	if (dup2(pipe_fd[P_READ_], STDIN_FILENO) < 0)
		print_error_exit("Dup2() error...");
	close(pipe_fd[P_READ_]);
	cmd_args = ft_split(argv[3], ' ');
	cmd_path = get_cmd_path(cmd_args[0], envp);
	if (cmd_path == NULL)
		print_error_exit("cmd path error...");
	if (execve(cmd_path, cmd_args, envp) < 0)
	{
		if (cmd_path != NULL)
			free(cmd_path);
		print_error_terminate_str_arr_exit(cmd_args, "Execve fail...");
	}
}

/**
 * @brief Get valid command path. If cmnd_str(param) has absolute address of 
 * command, cmd_str(param) will be returned. If not, matching address will be 
 * searched in envp(param).
 * 
 * @param cmd_str 
 * @param envp 
 * @return char* 
 */
static char	*get_cmd_path(char *cmd_str, char **envp)
{
	char	**path_array;
	char	*cmd_path;
	int		idx;

	if (ft_strchr(cmd_str, '/') != NULL)
		return (ft_strdup(cmd_str));
	idx = 0;
	while (envp[idx] != NULL && ft_strncmp(envp[idx], "PATH=", 5))
		idx++;
	if (envp[idx] == NULL)
		return (NULL);
	path_array = ft_split(envp[idx] + 5, ':');
	path_array = join_string_to_strings(path_array, ft_strjoin("/", cmd_str));
	idx = 0;
	while (path_array[idx] != NULL && access(path_array[idx], X_OK) != 0)
		idx++;
	if (path_array[idx] == NULL)
		cmd_path = NULL;
	else
		cmd_path = ft_strdup(path_array[idx]);
	terminate_str_arr(path_array);
	return (cmd_path);
}

/**
 * @brief Join str_to_join(param) to the end of each strings in str_arr(param).
 * 
 * @param str_arr 
 * @param str_to_join 
 * @return char** 
 */
static char	**join_string_to_strings(char **str_arr, char *str_to_join)
{
	int		idx;
	int		str_cnt;
	char	**joined_str_arr;

	str_cnt = count_strs(str_arr);
	joined_str_arr = malloc(sizeof(char *) * (str_cnt + 1));
	if (joined_str_arr == NULL)
		return (print_error_return_null(NULL));
	joined_str_arr[str_cnt] = NULL;
	idx = 0;
	while (idx < str_cnt)
	{
		joined_str_arr[idx] = ft_strjoin(str_arr[idx], str_to_join);
		idx++;
	}
	free(str_to_join);
	terminate_str_arr(str_arr);
	return (joined_str_arr);
}

/**
 * @brief Count the number of strings in str_arr(param)
 * 
 * @param str_arr 
 * @return int 
 */
static int	count_strs(char **str_arr)
{
	int	n;

	n = 0;
	while (str_arr[n] != NULL)
		n++;
	return (n);
}
