/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:41 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/31 15:43:45 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	display(t_pipex *pipex)
{
	int	i;
	int	j;

	printf("n of io_fd: %d, %d\n", pipex->infile_fd, pipex->outfile_fd);
	printf("n of pipes: %d\n", pipex->cmd_count);
	i = 0;
	printf("pipes fd: ");
	while (pipex->pipe_fds[i])
	{
		printf(" %d %d,", pipex->pipe_fds[i][0], pipex->pipe_fds[i][1]);
		i++;
	}
	i = 0;
	printf("\n=== cmds ===\n");
	while (pipex->cmd_paths[i])
	{
		j = 0;
		printf("%2d. ", i + 1);
		while (pipex->cmd_args[i][j])
		{
			printf(" %s", pipex->cmd_args[i][j++]);
		}
		printf("%3s %s\n", " ", pipex->cmd_paths[i]);
		i++;
	}
}

int	pipex(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;

	printf("pipex: %p %lu\n", &pipex, sizeof(pipex));
	printf("infile_fd: %p %lu\n", &pipex.infile_fd, sizeof(pipex.infile_fd));
	printf("outfile_fd: %p %lu\n", &pipex.outfile_fd, sizeof(pipex.outfile_fd));
	printf("pipe_fds: %p %lu\n", &pipex.pipe_fds, sizeof(pipex.pipe_fds));
	printf("cmd_count: %p %lu\n", &pipex.cmd_count, sizeof(pipex.cmd_count));
	printf("cmd_paths: %p %lu\n", &pipex.cmd_paths, sizeof(pipex.cmd_paths));
	printf("cmd_args: %p %lu\n", &pipex.cmd_args, sizeof(pipex.cmd_args));
	if (initialize_pipex(&pipex, argc, argv, env))
		return (1);
	// display(&pipex);
	// if (pipex_process(&pipex, env))
	// 	return (ft_puterror(PROGRAM, NULL, errno));
	// free_pipex(&pipex);
	return (0);
}
