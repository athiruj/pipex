/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:31:35 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/04 15:59:45 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static int	close_fd(int *infile);

/*
 *	close_all_fds() close all opened file
 *	Return 0 on success and return 1 when fail
 */
int	close_all_fds(int *infile, int *outfile, int **pipe_fds, int n_fds)
{
	int	i;

	if (infile && *infile > 2)
		close_fd(infile);
	if (outfile && *outfile > 2)
		close_fd(outfile);
	i = 0;
	while (i < n_fds)
	{
		if (pipe_fds[i][0] > 2 && pipe_fds[i][1] > 2)
		{
			if (close(pipe_fds[i][0]) == -1 || close(pipe_fds[i][1]) == -1)
			{
				perror("Failed to close file descriptor");
				return (1);
			}
			pipe_fds[i][0] = -1;
			pipe_fds[i][1] = -1;
		}
		i++;
	}
	return (0);
}

/*
 *	close_fds() close I/O file
 *	Return 0 on success and return 1 when fail
 */
static int	close_fd(int *fd)
{
	if (fd && *fd > 2)
	{
		if (close(*fd) == -1)
		{
			perror("Failed to close I/O file descriptor");
			return (1);
		}
		*fd = -1;
	}
	return (0);
}
