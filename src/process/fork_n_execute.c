/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_n_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:23:36 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/02 15:57:36 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static int	prepare_pipes(t_pipex *pipex, int i_pipe);

static int	execute_cmd(t_pipex *pipex, char **env, int n_pipe);

int	fork_n_execute(pid_t *pids, t_pipex *pipex, char **env)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execute_cmd(pipex, env, i))
				return (1);
		}
		else if (pid > 0)
			pids[i] = pid;
		else
		{
			perror("Failed to fork");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	prepare_pipes(t_pipex *pipex, int i_pipe)
{
	if (i_pipe == 0)
	{
		if (dup2(pipex->infile_fd, STDIN_FILENO) > 0
			|| dup2(pipex->pipe_fds[0][1], STDOUT_FILENO) > 0)
			return (0);
	}
	else if (i_pipe == pipex->cmd_count - 1)
	{
		if (dup2(pipex->pipe_fds[i_pipe - 1][0], STDIN_FILENO) > 0
		|| dup2(pipex->outfile_fd, STDOUT_FILENO) > 0)
			return (0);
	}
	else
	{
		if (dup2(pipex->pipe_fds[i_pipe - 1][0], STDIN_FILENO) > 0
		|| dup2(pipex->pipe_fds[i_pipe][1], STDOUT_FILENO) > 0)
			return (0);
	}
	perror("Failed to duplicate file descriptor");
	return (-1);
}

static int	execute_cmd(t_pipex *pipex, char **env, int n_pipe)
{
	if (!pipex
		|| prepare_pipes(pipex, n_pipe)
		|| close_all_fds(
			&pipex->infile_fd,
			&pipex->outfile_fd,
			pipex->pipe_fds,
			pipex->cmd_count - 1))
		return (1);
	if (execve(pipex->cmd_paths[n_pipe], pipex->cmd_args[n_pipe], env) == -1)
	{
		perror("Failed to execute the program");
		return (1);
	}
	return (0);
}
