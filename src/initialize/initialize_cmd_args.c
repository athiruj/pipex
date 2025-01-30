/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_cmd_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:16:27 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/30 14:19:14 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static char	**split_cmd_args(char *cmd_arg);

/*
 *	initialize_cmd_args()
 *	Return 0 on success and return 1 when fail
 */
int	initialize_cmd_args(char ****cmd_args, int cmd_count, char **argv, int hdoc)
{
	int	i;

	if (!cmd_args || !argv)
		return (1);
	*cmd_args = (char ***)malloc(sizeof(char **) * (cmd_count + 1));
	if (!(*cmd_args))
	{
		perror("Failed to allocate command arguments");
		return (1);
	}
	i = 0;
	(*cmd_args)[cmd_count] = 0;
	while (i < cmd_count)
	{
		(*cmd_args)[i] = split_cmd_args((argv + 2 + hdoc)[i]);
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

static int	count_word(char *str);

static char	*split_word(char *str, int with_space);

static void	free_split_cmd_args(char **cmd_args, int n_cmds);

/*
 *	split_cmd_arg() split a command with argument (similar ft_split)
 *  Return splitted command and argument if failed return NULL
 */
static char	**split_cmd_args(char *cmd_arg)
{
	char	**cmd_args;
	int		n_cmds;
	int		i;

	if (!cmd_arg)
		return (NULL);
	n_cmds = count_word(cmd_arg);
	cmd_args = (char **)ft_calloc(sizeof(char *), (n_cmds + 1));
	if (!cmd_args)
		return (NULL);
	i = 0;
	while (*cmd_arg && i < n_cmds)
	{
		while (i && *cmd_arg == ' ')
			cmd_arg++;
		cmd_args[i] = split_word(cmd_arg, i);
		if (!cmd_args[i])
		{
			free_split_cmd_args(cmd_args, i);
			free(cmd_args);
			return (NULL);
		}
		cmd_arg = cmd_arg + ft_strlen(cmd_args[i++]);
	}
	return (cmd_args);
}

static int	count_word(char *str)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (*str)
	{
		if (*str != ' ' && !s && ++i)
			s = 1;
		else if (*str == ' ' && s)
			s = 0;
		str++;
	}
	return (i);
}

static char	*split_word(char *str, int with_space)
{
	char	*word;
	int		i;

	i = 0;
	while (!with_space && str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	word = (char *)malloc(sizeof(char) * (i));
	if (!word)
		return (NULL);
	ft_strncpy(word, str, i);
	return (word);
}

static void	free_split_cmd_args(char **cmd_args, int n_cmds)
{
	int	i;

	if (!cmd_args || !n_cmds)
		return ;
	i = 0;
	while (i < n_cmds)
	{
		free(cmd_args[i]);
		cmd_args[i++] = NULL;
	}
}
