/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:51:16 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/13 23:42:56 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	initial_pipex(t_pipex *pipex, int argc, char *argv[], char *env[])
{
	if (!ft_strcmp("here_doc", argv[1]))
	{
		pipex->here_doc = True;
		pipex->pipes = argc - 5;
	}
	else
	{
		pipex->here_doc = False;
		pipex->pipes = argc - 4;
	}
	pipex->cmds = NULL;
	pipex->cmd_paths = NULL;
	pipex->pipe_fds = NULL;
	if (initial_io(pipex, argc, argv)
		|| initial_cmds(pipex, argc, argv, env)
		|| initial_pipes(pipex, argc))
	{
		free_pipex(pipex);
		return (-1);
	}
	return (0);
}
