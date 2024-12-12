/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:49:42 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/12 21:25:03 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	free_pipex(t_pipex	*pipe)
{
	if (pipe->cmds)
	{
		free_2d_array(pipe->cmds);
		free(pipe->cmds);
	}
	if (pipe->cmd_paths)
	{
		free_array(pipe->cmd_paths);
		free(pipe->cmd_paths);
	}
	return (0);
}
