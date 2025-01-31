/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:58:55 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/31 13:56:33 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static int	prepare_pipes(t_pipex *pipex, int i_pipe);

static int	wait_process(pid_t *pids);

int	execute_pipex(t_pipex *pipex, char **env)
{
	pid_t	*pids;

	pids = (pid_t *)malloc(sizeof(pid_t) * pipex->cmd_count);
	if (!pids)
	{
		perror("Failed to allocate process ids");
		return (1);
	}
	if (fork_n_execute(pids, pipex, env)
		|| wait_process(pids))
	{
		free(pids);
		close_pipe_fds(pipex->pipe_fds);
		return (1);
	}
	free(pids);
	close_pipe_fds(pipex->pipe_fds);
	return (0);
}

static int	wait_process(pid_t *pids)
{
	return (0);
}
