/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:35 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/26 17:03:58 by atkaewse         ###   ########.fr       */
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
int		initialize_pipe_fds(int ***pipe_fds, int n_pipes);
int		initialize_fds(int *infile, int *outfile, int argc, char **argv);
int		initialize_cmd_args(
			char ****cmd_args,
			int cmd_count,
			char **argv,
			int hdoc
			);
int		initialize_cmd_paths(
			char ***cmd_path,
			char ****cmd_args,
			int cmd_count,
			char **env
			);
int		setup_hdoc_fds(
			int *infile_fd,
			int *outfile_fd,
			char *outfile,
			char *eof
			);
int		setup_io_fds(
			int *infile_fd,
			int *outfile_fd,
			char *infile,
			char *outfile
			);

void	free_pipe_fds(int **pipe_fds);
void	free_cmd_args(char ***cmd_args);
// int		initialize_pipes(t_pipex *pipex, char **argv);

#endif