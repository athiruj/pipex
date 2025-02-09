/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:55:40 by athi              #+#    #+#             */
/*   Updated: 2025/02/09 18:22:54 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/errno.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;

	if (!count || !size)
		return (malloc(1));
	if (count > INT_MAX / size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	tmp = malloc(count * size);
	if (!tmp)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(tmp, count * size);
	return (tmp);
}
