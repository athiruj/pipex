/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_cmd_paths.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:28:36 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/28 02:36:17 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static char	**get_env_path(char **env);

static int	try_access(char **cmd_path, char *cmd, char **env);

static void	free_env_path(char **env_path);

static char	*create_cmd_path(char *path, char *cmd);

/*
 *	initialize_cmd_paths() initialize command paths
 *	Return 0 on success and return 1 when fail
 */
int	initialize_cmd_paths(
		char ***cmd_paths,
		char ***cmd_args,
		int cmd_count,
		char **env
		)
{
	int		i;
	char	**env_path;

	env_path = get_env_path(env);
	*cmd_paths = (char **)malloc(sizeof(char *) * (cmd_count + 1));
	if (!(*cmd_paths))
	{
		perror("Failed to allocate command path");
		return (1);
	}
	i = 0;
	while (i < cmd_count)
	{
		if (try_access(&(*cmd_paths)[i], cmd_args[i][0], env_path))
		{
			free_cmd_paths(*cmd_paths);
			free_env_path(env_path);
			free(env_path);
			return (1);
		}
		i++;
	}
	free_env_path(env_path);
	free(env_path);
	return (0);
}

/*
 *	get_env_path() find a PATH in ENV 
 *	return a pointer of subpath array
 */
static char	**get_env_path(char **env)
{
	char	**env_path;

	if (!env)
		return (NULL);
	while (*env)
	{
		if (!ft_strncmp("PATH=", *env, 5))
			return (env_path = ft_split(*env + 5, ':'));
		env++;
	}
	return (NULL);
}

/*
 *	try_access() try to access file program
 *	Return 0 on success and return 1 when fail
 */
static int	try_access(char **cmd_path, char *cmd, char **env_path)
{
	char	*tmp_path;

	if (!env_path)
		return (1);
	while (*env_path)
	{
		tmp_path = create_cmd_path(*env_path++, cmd);
		if (!tmp_path)
			return (1);
		if (access(tmp_path, F_OK) == 0)
		{
			*cmd_path = tmp_path;
			return (0);
		}
		free(tmp_path);
	}
	perror("Failed to access command");
	return (1);
}

/*
 *	create_cmd_path() create a path concat with command 
 *	Return full command path
 */
static char	*create_cmd_path(char *path, char *cmd)
{
	char	*cmd_path;
	int		len_cmd_path;

	if (cmd[0] == '/' || cmd[0] == '~'
		|| !ft_strncmp("./", cmd, 2) || !ft_strncmp("../", cmd, 3))
	{
		cmd_path = ft_strdup(cmd);
		if (!cmd_path)
		{
			perror("Failed to allocate command path");
			return (NULL);
		}
		return (cmd_path);
	}
	len_cmd_path = ft_strlen(path) + ft_strlen(cmd);
	cmd_path = (char *)malloc(sizeof(char) * (len_cmd_path + 2));
	if (!cmd_path)
	{
		perror("Failed to allocate command path");
		return (NULL);
	}
	ft_strcat(cmd_path, path);
	ft_strcat(cmd_path, "/");
	ft_strcat(cmd_path, cmd);
	return (cmd_path);
}

/*
 *	free_env_path() deallocate ENV path
 *	Not return
 */
static void	free_env_path(char **env_path)
{
	if (!env_path)
		return ;
	while (*env_path)
		free(*env_path++);
}
