/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:52:09 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/14 11:00:31 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/*
 *	Try to access file and return full path
 */
char	*try_access(char **env, char *cmd)
{
	char	*cmd_path;
	char	*tmp_path;

	if (!env || !cmd)
		return (NULL);
	while (*env)
	{
		cmd_path = ft_strjoin(*env, "/");
		tmp_path = cmd_path;
		cmd_path = ft_strjoin(tmp_path, cmd);
		free(tmp_path);
		if (!cmd_path)
			return (NULL);
		if (!access(cmd_path, F_OK))
			return (cmd_path);
		free(cmd_path);
		env++;
	}
	return (NULL);
}
