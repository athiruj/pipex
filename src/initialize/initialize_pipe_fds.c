/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_pipe_fds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:06:34 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/27 14:04:46 by atkaewse         ###   ########.fr       */
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
		(*pipe_fds)[i] = (int *)malloc(sizeof(int) * 2);
		if (!(*pipe_fds)[i] || pipe((*pipe_fds)[i]) == -1)
		{
			perror("Failed to create pipe");
			free_pipe_fds(*pipe_fds);
			return (1);
		}
		i++;
	}
	return (0);
}
