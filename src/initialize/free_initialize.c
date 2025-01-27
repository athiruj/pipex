/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:04:12 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/27 14:07:53 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/*
 *	free_pipe_fds() deallocates pipe file descriptor
 *	Not return
 */
void	free_pipe_fds(int **pipe_fds)
{
	int	i;

	if (!pipe_fds)
		return ;
	i = 0;
	while (pipe_fds[i])
	{
		if (pipe_fds[i])
			free(pipe_fds[i]);
		i++;
	}
}

/*
 *	free_cmd_args() deallocates command arguments
 *	Not return
 */
void	free_cmd_args(char ***cmd_args)
{
	int	i;
	int	j;

	if (!cmd_args)
		return ;
	i = 0;
	while (cmd_args[i])
	{
		j = 0;
		while (cmd_args[i][j])
			free(cmd_args[i][j++]);
		free(cmd_args[i++]);
	}
}

/*
 *	free_cmd_paths() deallocates command paths
 *	Not return
 */
void	free_cmd_paths(char **cmd_paths)
{
	if (!cmd_paths)
		return ;
	while (*cmd_paths)
		free(*cmd_paths++);
}
