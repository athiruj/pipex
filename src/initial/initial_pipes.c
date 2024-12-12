/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:03:42 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/11 15:49:26 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	initial_pipes(t_pipex *pipe, int argc)
{
	if (!pipe || !argc)
		return (-1);
	printf("number of pipes %d\n", pipe->pipes);
	return (0);
}
