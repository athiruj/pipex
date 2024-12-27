/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:41 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/27 12:27:05 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	display(t_pipex *pipex)
{
	int	i;
	int	j;

	printf("n of io_fd: %d, %d\n", pipex->io_fds[0], pipex->io_fds[1]);
	printf("n of pipes: %d\n", pipex->process);
	i = 0;
	printf("pipes fd: ");
	while (pipex->pipe_fds[i])
	{
		printf(" %d %d,", pipex->pipe_fds[i][0], pipex->pipe_fds[i][1]);
		i++;
	}
	i = 0;
	printf("\n=== cmds ===\n");
	while (pipex->cmds[i])
	{
		j = 0;
		printf("%2d. ", i + 1);
		while (pipex->cmds[i][j])
		{
			printf(" %s", pipex->cmds[i][j++]);
		}
		printf("%3s %s\n", " ", pipex->cmd_paths[i]);
		i++;
	}
}

int	pipex(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;

	if (initial_pipex(&pipex, argc, argv, env))
		return (ft_puterror(PROGRAM, NULL, errno));
	display(&pipex);
	// if (pipex_process(&pipex, env))
	// 	return (ft_puterror(PROGRAM, NULL, errno));
	// free_pipex(&pipex);
	return (0);
}
