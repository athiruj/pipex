/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:35 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/14 12:08:48 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>
# include <sys/errno.h>

# include "../submodule/libft/libft.h"
# include "../submodule/get_next_line/get_next_line.h"

# define PROGRAM "pipex"

typedef struct s_pipex
{
	int		io_fds[2];
	int		**pipe_fds;
	int		pipes;
	char	***cmds;
	char	**cmd_paths;
	t_bool	here_doc;
}	t_pipex;

int		pipex(int argc, char *argv[], char *env[]);

int		initial_pipex(t_pipex *pipex, int argc, char *argv[], char *env[]);
int		initial_io(t_pipex *pipex, int argc, char *argv[]);
int		initial_cmds(t_pipex *pipex, int argc, char *argv[], char *env[]);
int		initial_pipes(t_pipex *pipex, int argc);

int		pipex_process(t_pipex *pipex);

char	*try_access(char **env, char *cmd);
int		free_pipex(t_pipex *pipex);
int		free_iarray(int **arr);
int		free_array(char **arr);
int		free_2d_array(char ***arr);
int		ft_puterror(char *program, char *target, int err_no);

#endif