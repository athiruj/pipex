/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:35 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/12 21:26:57 by atkaewse         ###   ########.fr       */
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
// # include <errno.h>
# include <string.h>
# include <sys/errno.h>

# include "../submodule/libft/libft.h"
# include "../submodule/get_next_line/get_next_line.h"

# define PROGRAM "pipex"

typedef struct s_pipex
{
	int		io_fds[2];
	int		**pipe_fds;
	char	***cmds;
	char	**cmd_paths;
	int		pipes;
	int		status;
	t_bool	here_doc;
}	t_pipex;

int		initial_pipex(t_pipex *pipe, int argc, char *argv[], char *env[]);

int		initial_io(t_pipex *pipe, int argc, char *argv[]);
int		initial_cmds(t_pipex *pipe, int argc, char *argv[], char *env[]);
int		initial_pipes(t_pipex *pipe, int argc);

void	create_path(char **cmd_path, char *path, char *cmd);
int		free_pipex(t_pipex *pipe);
int		free_array(char **arr);
int		free_2d_array(char ***arr);
int		ft_puterror(char *program, char *target, int err_no);

#endif