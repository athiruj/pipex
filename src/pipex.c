/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:41 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/09 17:33:10 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (argv[1] && !ft_strcmp("here_doc", argv[1]) && argc < 6)
	{
		ft_putstr_fd("Usage: here_doc <EOF> <command1> <command2> \
... [commandN] <destination_file>", 2);
		return (EINVAL);
	}
	if (argc < 5)
	{
		ft_putstr_fd("Usage: <source_file> <command1> <command2> \
... [commandN] <destination_file>", 2);
		return (EINVAL);
	}
	if (pipex(argc, argv, env))
		return (1);
	return (0);
}

/*
 *	pipex() Do pipex
 *	Return 0 on success and return 1 when fail
 */
int	pipex(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (initialize_pipex(&pipex, argc, argv, env)
		|| process_pipex(&pipex, env))
	{
		free_pipex(&pipex);
		return (1);
	}
	free_pipex(&pipex);
	return (0);
}
