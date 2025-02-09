/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:58:55 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/09 19:37:35 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static int	wait_process(t_pipex *pipx, pid_t *pids, int n_pids);

/*
 *	process_pipex() Do pipex process
 *	Return 0 on success and return 1 when fail
 */
int	process_pipex(t_pipex *pipex, char **env)
{
	pid_t	*pids;

	pids = (pid_t *)ft_calloc(sizeof(pid_t), pipex->cmd_count);
	if (!pids)
	{
		perror("Failed to allocate process ids");
		return (1);
	}
	if (fork_n_execute(pids, pipex, env)
		|| wait_process(pipex, pids, pipex->cmd_count))
	{
		free(pids);
		return (1);
	}
	free(pids);
	return (0);
}

/*
 *	wait_process() close all file and wait all processes 
 *	Return 0 on success and return 1 when fail
 */
static int	wait_process(t_pipex *pipex, pid_t *pids, int n_pids)
{
	int	i;
	int	status;

	if (!pids || close_all_fds(
			&pipex->infile_fd, &pipex->outfile_fd,
			pipex->pipe_fds,
			pipex->cmd_count - 1))
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
