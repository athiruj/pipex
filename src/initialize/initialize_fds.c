/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:47:44 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/30 22:28:59 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static int	set_up_hdoc_fds(
				int *infile_fd,
				int *outfile_fd,
				char *outfile,
				char *end
				);

static int	set_up_io_fds(
				int *infile_fd,
				int *outfile_fd,
				char *infile,
				char *outfile
				);

int	initialize_fds(int *infile_fd, int *outfile_fd, int argc, char **argv)
{
	if (!infile_fd || !outfile_fd || !argc || !argv)
		return (EXIT_FAILURE);
	if (!ft_strcmp("here_doc", argv[1]))
	{
		if (set_up_hdoc_fds(infile_fd, outfile_fd, argv[argc - 1], argv[2]))
			return (EXIT_FAILURE);
	}
	else
		if (set_up_io_fds(infile_fd, outfile_fd, argv[1], argv[argc - 1]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	set_up_hdoc_fds(
	int *infile_fd,
	int *outfile_fd,
	char *outfile,
	char *end
	)
{
	if (!infile_fd || !outfile_fd || !outfile || !end)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	set_up_io_fds(
	int *infile_fd,
	int *outfile_fd,
	char *infile,
	char *outfile
	)
{
	if (!infile_fd || !outfile_fd || !infile || !outfile)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
