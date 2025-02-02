/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:58:55 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/03 01:46:42 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static int	wait_process(pid_t *pids, int n_pids);

int	process_pipex(t_pipex *pipex, char **env)
{
	pid_t	*pids;

	pids = (pid_t *)malloc(sizeof(pid_t) * pipex->cmd_count);
	if (!pids)
	{
		perror("Failed to allocate process ids");
		return (1);
	}
	if (fork_n_execute(pids, pipex, env)
		|| wait_process(pids, pipex->cmd_count))
	{
		free(pids);
		close_all_fds(
			&pipex->infile_fd, &pipex->outfile_fd,
			pipex->pipe_fds,
			pipex->cmd_count - 1);
		return (1);
	}
	free(pids);
	return (0);
}

static int	wait_process(pid_t *pids, int n_pids)
{
	int	i;
	int	status;

	if (!pids)
		return (1);
	i = 0;
	while (i < n_pids)
	{
		if (waitpid(pids[i], &status, 0) == -1)
		{
			perror("Failed to wait process");
			return (-1);
		}
		i++;
	}
	return (0);
}
