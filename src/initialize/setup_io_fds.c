/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_io_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:47:44 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/31 23:34:11 by atkaewse         ###   ########.fr       */
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
	return (0);
}
