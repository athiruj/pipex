/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_pipex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:51:16 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/03 01:31:51 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	display(t_pipex *pipex)
{
	int	i;
	int	j;

	printf("io_fd: %d, %d\n", pipex->infile_fd, pipex->outfile_fd);
	i = 0;
	printf("pipes fd: ");
	while (pipex->pipe_fds && pipex->pipe_fds[i])
	{
		printf(" %d %d,", pipex->pipe_fds[i][0], pipex->pipe_fds[i][1]);
		i++;
	}
	printf("\n=== cmds ===\n");
	printf("cmd count: %d\n", pipex->cmd_count);
	i = 0;
	while (pipex->cmd_args[i])
	{
		j = 0;
		printf("%2d. >", i + 1);
		while (pipex->cmd_args[i][j])
			printf("%s ", pipex->cmd_args[i][j++]);
		if (pipex->cmd_paths && pipex->cmd_paths[i])
			printf("%3s %s\n", " ", pipex->cmd_paths[i]);
		i++;
	}
}

/*
 *	initialize_pipex() initialize child of pipex 
 *	Return 0 on success and return 1 when fail
 */
int	initialize_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	int	hdoc;

	hdoc = 0;
	if (!pipex || !argc || !argv || !env)
		return (1);
	if (!ft_strcmp("here_doc", argv[1]))
		hdoc = 1;
	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;
	pipex->pipe_fds = NULL;
	pipex->cmd_count = argc - 3 - hdoc;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	if (initialize_fds(&pipex->infile_fd, &pipex->outfile_fd, argc, argv)
		|| initialize_pipe_fds(&(pipex->pipe_fds), pipex->cmd_count - 1)
		|| initialize_cmd_args(&(pipex->cmd_args), pipex->cmd_count, argv, hdoc)
		|| initialize_cmd_paths(&(pipex->cmd_paths), pipex->cmd_args,
			pipex->cmd_count, env))
	{
		free_pipex(pipex);
		return (1);
	}
	// display(pipex);
	return (0);
}
