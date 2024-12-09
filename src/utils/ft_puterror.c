/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 08:19:54 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/07 10:34:16 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	ft_puterror(char *program, char *target, int err_no)
{
	if (program)
	{
		ft_putstr_fd(program, 2);
		write(2, ": ", 2);
	}
	if (err_no)
		ft_putstr_fd(strerror(err_no), 2);
	if (target)
	{
		write(2, " ", 1);
		ft_putstr_fd(target, 2);
	}
	write(2, "\n", 1);
	return (err_no);
}
