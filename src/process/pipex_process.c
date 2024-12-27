/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:10:09 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/26 23:17:38 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	prepare_io_pipes(t_pipex *pipex, int idx)
{
	if (idx == 0)
	{
		if (dup2(pipex->io_fds[0], STDIN_FILENO) == -1
			|| dup2(pipex->pipe_fds[0][1], STDOUT_FILENO) == -1)
				return (-1);
	}
	else if (idx == pipex->process)
	{
		if (dup2(pipex->pipe_fds[idx - 1][0], STDIN_FILENO) == -1
			|| dup2(pipex->io_fds[1], STDOUT_FILENO) == -1)
			return (-1);
	}
	else
	{
		if (dup2(pipex->pipe_fds[idx - 1][0], STDIN_FILENO) == -1
			|| dup2(pipex->pipe_fds[idx][1], STDOUT_FILENO) == -1)
			return (-1);
	}
	return (0);
}

int	wait_process(pid_t *pids, int n_pipes)
{
	int	i;

	if (pids)
		return (-1);
	i = 0;
	while (i < n_pipes)
		if (waitpid(pids[i++], NULL, 0) == -1)
			exit(-1);
	return (0);
}

int	pipex_process(t_pipex *pipex, char **env)
{
	int		i;
	pid_t	pid;
	pid_t	*pids;

	i = 0;
	pids = (pid_t *)malloc(sizeof(pid_t) * (pipex->process + 1));
	while (i <= pipex->process && pids)
	{
		pid = fork();
		if (pid < 0)
			exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			if (prepare_io_pipes(pipex, i))
				exit(ft_puterror(PROGRAM, NULL, EPIPE));
			close_all_fds(pipex);
			if (execve(pipex->cmd_paths[i], pipex->cmds[i], env))
				exit(EXIT_FAILURE);
			exit (EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			pids[i] = pid;
		}
		i++;
	}
	free(pids);
	close_all_fds(pipex);
	wait_process(pids, pipex->process);
	return (0);
}
