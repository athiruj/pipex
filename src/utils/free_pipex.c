/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:49:42 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/14 11:08:14 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	free_pipex(t_pipex	*pipex)
{
	if (pipex->cmds)
	{
		free_2d_array(pipex->cmds);
		free(pipex->cmds);
	}
	if (pipex->cmd_paths)
	{
		free_array(pipex->cmd_paths);
		free(pipex->cmd_paths);
	}
	if (pipex->pipe_fds)
	{
		free_iarray(pipex->pipe_fds);
		free(pipex->pipe_fds);
	}
	return (0);
}
