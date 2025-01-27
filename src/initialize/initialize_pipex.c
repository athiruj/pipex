/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_pipex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:51:16 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/27 14:14:38 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

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
		// free all here
		return (1);
	}
	return (0);
}
