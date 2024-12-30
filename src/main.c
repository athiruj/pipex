/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:11:32 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/30 13:47:26 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char *env[])
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
	pipex(argc, argv, env);
	return (EXIT_SUCCESS);
}
