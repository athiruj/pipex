/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:35 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/30 22:30:29 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/errno.h>

# include "../submodule/libft/libft.h"
# include "../submodule/get_next_line/get_next_line.h"

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		**pipe_fds;
	int		cmd_count;
	char	**cmd_paths;
	char	***cmd_args;
}	t_pipex;

int		pipex(int argc, char *argv[], char *env[]);

int		initialize_pipex(t_pipex *pipex, int argc, char **argv, char **env);
int		initialize_fds(int *infile, int *outfile, int argc, char **argv);
// int		initialize_cmds(t_pipex *pipex, char **argv);
// int		initialize_pipes(t_pipex *pipex, char **argv);

#endif