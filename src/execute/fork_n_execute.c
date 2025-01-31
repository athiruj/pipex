/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_n_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:23:36 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/31 13:49:35 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void check_fd(int *fd, int n) {
	int i = 0;
	while (i < n)
	{
    	if (fcntl(fd[i], F_GETFD) > 0) {
        	printf("File descriptor %d is still open.\n", fd[i]);
    	} else {
        	printf("File descriptor %d is closed.\n", fd[i]);
    	}
		i++;
	}
}

static int	prepare_pipes(t_pipex *pipex, int i_pipe);

int	fork_n_execute(pid_t *pids, t_pipex *pipex, char **env)
{
	pid_t	pid;

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
