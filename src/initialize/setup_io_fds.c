/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_io_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:47:44 by atkaewse          #+#    #+#             */
/*   Updated: 2025/01/24 15:19:28 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/*
 *	setup_io_fds() set up in/out file descriptor
 *	Return 0 on success and return 1 when fail
 */
int	setup_io_fds(
	int *infile_fd,
	int *outfile_fd,
	char *infile,
	char *outfile
	)
{
	if (!infile_fd || !outfile_fd || !infile || !outfile)
		return (1);
	*infile_fd = open(infile, O_RDONLY);
	if (*infile_fd == -1)
	{
		perror("Failed to open file");
		return (1);
	}
	*outfile_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, \
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (*outfile_fd == -1)
	{
		close(*infile_fd);
		perror("Failed to open file");
		return (1);
	}
	return (0);
}
