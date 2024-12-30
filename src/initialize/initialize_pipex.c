/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_pipex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:51:16 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/30 22:29:12 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	initialize_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	if (!pipex || !argc || !argv || !env)
		return (EXIT_FAILURE);
	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;
	pipex->pipe_fds = NULL;
	if (!ft_strcmp("here_doc", argv[1]))
		pipex->cmd_count = argc - 5;
	else
		pipex->cmd_count = argc - 4;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	if (initialize_fds(&pipex->infile_fd, &pipex->outfile_fd, argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
