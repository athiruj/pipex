/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_pipe_fds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:06:34 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/22 16:53:21 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/*
 *	initialize_pipe_fds() 
 *
 */
int	initialize_pipe_fds(int **pipe_fds, int n_pipes)
{
	int	i;

	if (!pipe_fds || !n_pipes)
		return (0);
	pipe_fds = (int **)malloc(sizeof(int *) * n_pipes);
	if (!pipe_fds)
	{
		perror("pipes allocate failed");
		return (1);
	}
	i = 0;
	while(i < n_pipes)
	{
		pipe_fds[i] = (int *)ft_calloc(2, sizeof(int));
		if (pipe_fds[i])
		{
			perror("pipe allocate failed");
			free_pipes(pipe_fds, n_pipes);
			return (1);
		}
	}
	return (0);
}

int	free_pipes(int **pipes_fds, int n_pipes)
{
	int	i;

	if (!pipes_fds)
		return (0);
	i = 0;
	while (i < n_pipes)
	{
		if (pipes_fds[i])
			free(pipes_fds[i]);
		i++;
	}
	return (0);
}
