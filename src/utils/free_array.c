/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:18:36 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/14 11:06:12 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	free_iarray(int **arr)
{
	int	**tmp;

	if (!arr)
		return (-1);
	tmp = arr;
	while (*tmp)
		free(*tmp++);
	return (0);
}

int	free_array(char **arr)
{
	char	**tmp;

	if (!arr)
		return (-1);
	tmp = arr;
	while (*tmp)
		free(*tmp++);
	return (0);
}

int	free_2d_array(char ***arr)
{
	char	***tmp;

	if (!arr)
		return (-1);
	tmp = arr;
	while (*tmp)
	{
		free_array(*tmp);
		free(*tmp++);
	}
	return (0);
}
