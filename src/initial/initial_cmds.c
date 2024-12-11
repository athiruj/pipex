/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:56:11 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/11 23:56:52 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/*
 *	Splitting a set of commands 
 *	return a pointer of pointer of commands array
 */
static char	***split_cmds(int n, char *argv[])
{
	char	***cmds;
	int		i;

	if (!n || !argv)
		return (NULL);
	i = 0;
	cmds = (char ***)malloc(sizeof(char **) * (n + 1));
	while (i < n)
	{
		cmds[i] = ft_split(argv[i], ' ');
		i++;
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
			break ;
		i++;
	}
	env_path = ft_split(env[i] + 5, ':');
	if (!env_path)
		return (NULL);
	return (env_path);
}

/*
 *	Verify a PATH with command try to access 
 *	return a pointer of matching command path array
 */
static char	**verify_cmd_paths(char ***cmds, char **paths, int n_cmds)
{
	char	**cmd_paths;
	char	*tmp_cmd_path;
	char	**tmp_paths;
	int		i;

	if (!cmds || !paths || !n_cmds)
		return (NULL);
	i = 0;
	cmd_paths = (char **)malloc(sizeof(char *) * (n_cmds + 1));
	while (i < n_cmds)
	{
		tmp_paths = paths;
		while (*tmp_paths)
		{
			tmp_cmd_path = ft_strjoin(*tmp_paths++, "/");
			ft_strcat(tmp_cmd_path, cmds[i][0]);
			if (!access(tmp_cmd_path, F_OK))
			{
				cmd_paths[i] = tmp_cmd_path;
				break ;
			}
			// free(tmp_cmd_path);
		}
		i++;
	}
	return (cmd_paths);
}

/*
 *	Return a Path of commands
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
	if (!cmd_paths)
	{
		free_array(env_paths);
		return (NULL);
	}
	free_array(env_paths);
	return (cmd_paths);
}

/*
 *	Initialize Command and Command path
 */
int	initial_cmds(t_pipex *pipe, int argc, char *argv[], char *env[])
{
	if (!pipe)
		return (-1);
	pipe->cmds = split_cmds(pipe->pipes + 1, argv + 2 + pipe->here_doc);
	if (!pipe->cmds)
		return (-1);
	pipe->cmd_paths = get_cmd_paths(pipe->cmds, pipe->pipes + 1, env);
	while (*pipe->cmd_paths)
		printf("%s\n", *pipe->cmd_paths++);
	// if (!pipe->cmd_paths)
	// {
	// 	free_2d_array(pipe->cmds);
	// 	return (-1);
	// }
	return (0);
}
