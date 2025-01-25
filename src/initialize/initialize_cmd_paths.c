/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_cmd_paths.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:28:36 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/24 16:51:31 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/*
 *	initialize_cmd_paths()
 *
 */
int	initialize_cmd_paths(
		char ***cmd_path,
		char ****cmd_args,
		int cmd_count,
		char **env
		)
{
	if (!cmd_path || !cmd_args || !env)
		return (1);
	return (0);
}
