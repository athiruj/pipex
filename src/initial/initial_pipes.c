/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:03:42 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/16 15:38:59 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/*
 *	Intialize pipes file descriptor
 */
int	initial_pipes(t_pipex *pipex, int argc)
{
	int	i;

	if (!pipex || !argc)
		return (-1);
	pipex->pipe_fds = (int **)malloc(sizeof(int *) * (pipex->process + 1));
	if (!pipex->pipe_fds)
		return (ft_puterror(PROGRAM, NULL, errno));
	i = 0;
	while (i < pipex->process)
	{
		pipex->pipe_fds[i] = ft_calloc(2, sizeof(2));
		if (!pipex->pipe_fds[i])
		{
			free(pipex->pipe_fds);
			return (ft_puterror(PROGRAM, NULL, errno));
		}
		if (pipe(pipex->pipe_fds[i]) == -1)
			return (ft_puterror(PROGRAM, NULL, errno));
		i++;
	}
	return (0);
}
