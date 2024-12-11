/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:44:46 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/11 15:14:30 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*read_here_doc(const char *eof)
{
	char	*here_doc_str;
	char	*tmp_here_doc;
	char	*tmp_line;

	write(1, "pipe heredoc> ", 15);
	tmp_line = get_next_line(0);
	if (ft_strcmp(tmp_line, eof) != '\n')
	{
		write(1, "pipe heredoc> ", 15);
		tmp_here_doc = get_next_line(0);
		while ((ft_strcmp(tmp_line, eof) != '\n')
			&& (ft_strcmp(tmp_here_doc, eof) != '\n'))
		{
			here_doc_str = ft_strjoin(tmp_here_doc, tmp_line);
			free(tmp_line);
			free(tmp_here_doc);
			tmp_here_doc = here_doc_str;
			write(1, "pipe heredoc> ", 15);
			tmp_line = get_next_line(0);
		}
		free(tmp_here_doc);
	}
	free(tmp_line);
	return (here_doc_str);
}
