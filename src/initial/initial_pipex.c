/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:51:16 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/12 21:16:33 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	initial_pipex(t_pipex *pipe, int argc, char *argv[], char *env[])
{
	if (!ft_strcmp("here_doc", argv[1]))
	{
		pipe->here_doc = True;
		pipe->pipes = argc - 5;
	}
	else
	{
		pipe->here_doc = False;
		pipe->pipes = argc - 4;
	}
	if (initial_io(pipe, argc, argv)
		|| initial_cmds(pipe, argc, argv, env)
		|| initial_pipes(pipe, argc))
	{
		free_pipex(pipe);
		return (-1);
	}
	printf("%d %d\n", pipe->io_fds[0], pipe->io_fds[1]);
	int i = 0;
	int j = 0;
	while (pipe->cmds[i])
	{
		j = 0;
		while (pipe->cmds[i][j])
			printf("%s ", pipe->cmds[i][j++]);
		printf("\n");
		i++;
	}
	i = 0;
	while (pipe->cmd_paths[i])
		printf("%s\n", pipe->cmd_paths[i++]);
	// free_2d_array(pipe->cmds);
	// free(pipe->cmds);
	// free_array(pipe->cmd_paths);
	free_pipex(pipe);
	return (0);
}
