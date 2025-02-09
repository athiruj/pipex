/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:47:44 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/31 23:16:07 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/*
 *	initialize_fds() initialize in/out file descriptor
 *	Return 0 on success and return 1 when fail
 */
int	initialize_fds(int *infile_fd, int *outfile_fd, int argc, char **argv)
{
	if (!infile_fd || !outfile_fd || !argc || !argv)
		return (1);
	if (!ft_strcmp("here_doc", argv[1]))
	{
		if (setup_hdoc_fds(infile_fd, outfile_fd, argv[argc - 1], argv[2]))
			return (1);
	}
	else
		if (setup_io_fds(infile_fd, outfile_fd, argv[1], argv[argc - 1]))
			return (1);
	return (0);
}
