/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:09:52 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/11 17:48:59 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	free_2d_array(char ***arr)
{
	if (!arr)
		return (-1);
	while (*arr)
	{
		free_array(*arr);
		free(*arr++);
	}
	return (0);
}
