/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_pipe_fds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:06:34 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/26 17:05:29 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/*
 *	initialize_pipe_fds() set pipes file descriptor
 *	Return 0 on successed and return 1 when fail
 */
int	initialize_pipe_fds(int ***pipe_fds, int n_pipes)
{
	int	i;

	if (!pipe_fds || !n_pipes)
		return (0);
	*pipe_fds = (int **)malloc(sizeof(int *) * (n_pipes + 1));
	if (!(*pipe_fds))
	{
		perror("Failed to allocate pipe");
		return (1);
	}
	i = 0;
	(*pipe_fds)[n_pipes] = 0;
	while (i < n_pipes)
	{
		(*pipe_fds)[i] = (int *)ft_calloc(2, sizeof(int));
		if (!(*pipe_fds)[i] || pipe((*pipe_fds)[i]) == -1)
		{
			perror("Failed to allocate pipe");
			free_pipe_fds(*pipe_fds);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
 *	free_pipe_fds() deallocates pipe file descriptor
 *	Not return
 */
void	free_pipe_fds(int **pipe_fds)
{
	int	i;

	if (!pipe_fds)
		return ;
	i = 0;
	while (pipe_fds[i])
	{
		if (pipe_fds[i])
			free(pipe_fds[i]);
		i++;
	}
	free(pipe_fds);
}
