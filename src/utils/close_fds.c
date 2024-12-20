/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:44:00 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/18 10:27:58 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/*
 *	Close file descripter idex
 */
int	close_fds(t_pipex *pipex, int idx)
{
	if (idx == 0)
		close(pipex->io_fds[0]);
	else if (pipex->pipe_fds)
		close(pipex->pipe_fds[idx - 1][0]);
	if (idx == pipex->process - 1)
		close(pipex->io_fds[1]);
	else if (pipex->pipe_fds)
		close(pipex->pipe_fds[idx][1]);
	return (0);
}

/*
 *	Close file descripter except idex
 */
int	close_except_fds(t_pipex *pipex, int idx)
{
	int	i;

	i = 0;
	if (idx != 0 && pipex->io_fds[0])
		close(pipex->io_fds[0]), fprintf(stderr, "close in: %d\n", pipex->io_fds[0]);
	if (idx != pipex->process - 1 && pipex->io_fds[1])
		close(pipex->io_fds[1]), fprintf(stderr, "close out: %d\n", pipex->io_fds[1]);
	while (pipex->pipe_fds && i < pipex->process)
	{
		if (i != idx - 1)
		{
			fprintf(stderr, "close read: %d\n", pipex->pipe_fds[i][0]);
			close(pipex->pipe_fds[i][0]);
		}
		if (i != idx)
		{
			fprintf(stderr, "close write: %d\n", pipex->pipe_fds[i][1]);
			close(pipex->pipe_fds[i][1]);
		}
		i++;
	}
	fprintf(stderr, "++++++++++++++++++\n");
	return (0);
}
