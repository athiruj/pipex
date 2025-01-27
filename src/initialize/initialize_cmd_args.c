/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_cmd_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:16:27 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/27 14:08:18 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	free_cmd_args(char ***cmd_args);

/*
 *	initialize_cmd_args()
 *
 */
int	initialize_cmd_args(char ****cmd_args, int cmd_count, char **argv, int hdoc)
{
	int	i;

	if (!cmd_args || !argv)
		return (1);
	*cmd_args = (char ***)malloc(sizeof(char **) * (cmd_count + 1));
	if (!(*cmd_args))
	{
		perror("Failed to allocate command argument");
		return (1);
	}
	i = 0;
	(*cmd_args)[cmd_count] = 0;
	while (i < cmd_count)
	{
		(*cmd_args)[i] = ft_split((argv + 2 + hdoc)[i], ' ');
		if (!(*cmd_args)[i])
		{
			perror("Failed to allocate command argument");
			free_cmd_args(*cmd_args);
			return (1);
		}
		i++;
	}
	return (0);
}
