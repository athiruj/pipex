/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_cmd_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:16:27 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/24 17:01:12 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/*
 *	initialize_cmd_args()
 *
 */
int	initialize_cmd_args(char ****cmd_args, int cmd_count, char **argv)
{
	if (!cmd_args || !argv)
		return (1);
	*cmd_args = (char ***)malloc(sizeof(char **) * cmd_count);
	if (!(*cmd_args))
	{
		perror("Failed to allocate command argument");
		return (1);
	}
	// fprintf(stdout, "Hello\n");
	return (0);
}
