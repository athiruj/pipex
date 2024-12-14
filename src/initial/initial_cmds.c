/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:56:11 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/14 11:01:02 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/*
 *	Splitting a set of commands 
 *	return a pointer of pointer of commands array
 */
static char	***split_cmds(int n_cmds, char *argv[])
{
	char	***cmds;
	int		i;

	if (!n_cmds || !argv)
		return (NULL);
	i = 0;
	cmds = (char ***)malloc(sizeof(char **) * (n_cmds + 1));
	if (!cmds)
		return (NULL);
	while (i < n_cmds)
	{
		cmds[i] = ft_split(argv[i], ' ');
		if (!cmds[i++])
		{
			free_2d_array(cmds);
			return (NULL);
		}
	}
	return (cmds);
}

/*
 *	Find a PATH in ENV 
 *	return a pointer of subpath array
 */
static char	**get_env_path(char *env[])
{
	char	**env_path;
	int		i;

	if (!env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
			return (env_path = ft_split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

/*
 *	Verify a PATH with command try to access 
 *	return a pointer of matching command path array
 */
static char	**verify_cmd_paths(char ***cmds, char **env_paths, int n_cmds)
{
	char	**cmd_paths;
	char	**tmp_env;
	int		i;

	cmd_paths = (char **)malloc(sizeof(char *) * (n_cmds + 1));
	if (!cmd_paths)
		return (NULL);
	i = 0;
	while (i < n_cmds)
	{
		cmd_paths[i] = try_access(env_paths, cmds[i][0]);
		if (!cmd_paths[i])
		{
			free(cmd_paths);
			return (NULL);
		}
		i++;
	}
	return (cmd_paths);
}

/*
 *	Return a Path with commands
 */
static char	**get_cmd_paths(char ***cmds, int n_cmds, char *env[])
{
	char	**cmd_paths;
	char	**env_paths;

	if (!cmds || !n_cmds || !env)
		return (NULL);
	env_paths = get_env_path(env);
	if (!env_paths)
		return (NULL);
	cmd_paths = verify_cmd_paths(cmds, env_paths, n_cmds);
	free_array(env_paths);
	free(env_paths);
	if (!cmd_paths)
		return (NULL);
	return (cmd_paths);
}

/*
 *	Initialize Command and Command path
 */
int	initial_cmds(t_pipex *pipex, int argc, char *argv[], char *env[])
{
	if (!pipex)
		return (-1);
	pipex->cmds = split_cmds(pipex->pipes + 1, argv + 2 + pipex->here_doc);
	if (!pipex->cmds)
		return (-1);
	pipex->cmd_paths = get_cmd_paths(pipex->cmds, pipex->pipes + 1, env);
	if (!pipex->cmd_paths)
		return (-1);
	return (0);
}
