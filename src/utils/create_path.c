/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:52:09 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/12 15:38:59 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	create_path(char **cmd_path, char *path, char *cmd)
{
	if (!cmd_path)
		return ;
	ft_strcpy(*cmd_path, path);
	ft_strcat(*cmd_path, "/");
	ft_strcat(*cmd_path, cmd);
}
