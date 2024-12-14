/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:47:44 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/14 11:57:02 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static char	*read_here_doc(const char *eof)
{
	char	*here_doc_str;
	char	*tmp_here_doc;
	char	*tmp_line;

	write(1, "pipex heredoc> ", 15);
	tmp_line = get_next_line(0);
	if (ft_strcmp(tmp_line, eof) != '\n')
	{
		write(1, "pipex heredoc> ", 15);
		tmp_here_doc = get_next_line(0);
		while (tmp_line && (ft_strcmp(tmp_line, eof) != '\n')
			&& (ft_strcmp(tmp_here_doc, eof) != '\n'))
		{
			here_doc_str = ft_strjoin(tmp_here_doc, tmp_line);
			free(tmp_line);
			free(tmp_here_doc);
			tmp_here_doc = here_doc_str;
			write(1, "pipex heredoc> ", 15);
			tmp_line = get_next_line(0);
		}
		free(tmp_here_doc);
	}
	free(tmp_line);
	return (here_doc_str);
}

/*
 *	Open I/O pipex
 *	Return 0 if SUCCESS and return -1 when fail
 */
static int	pipe_io(char *infile, char *outfile, int fds[2])
{
	if (!fds)
		return (-1);
	fds[0] = open(infile, O_RDONLY);
	if (fds[0] == -1)
		return (ft_puterror(PROGRAM, infile, errno));
	fds[1] = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, \
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fds[1] == -1)
		return (errno);
	return (0);
}

/*
 *	Open I/O pipex for here_doc
 *	Return 0 if SUCCESS and return -1 when fail
 */
static int	pipe_io_here_doc(char *eof, char *outfile, int fds[2])
{
	int		tmp_io[2];
	char	*tmp_here_doc;

	if (!fds)
		return (-1);
	if (pipe(tmp_io) == -1)
		exit (ft_puterror(PROGRAM, NULL, errno));
	fds[0] = tmp_io[0];
	tmp_here_doc = read_here_doc(eof);
	if (tmp_here_doc)
		write(tmp_io[1], tmp_here_doc, ft_strlen(tmp_here_doc));
	close(tmp_io[1]);
	fds[1] = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, \
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fds[1] == -1)
	{
		close(tmp_io[0]);
		return (ft_puterror(PROGRAM, outfile, errno));
	}
	return (0);
}

/*
 *	Initial file descriptor for I/O pipex
 *	Return 0 if SUCCESS and return -1 when fail
 */
int	initial_io(t_pipex *pipex, int argc, char *argv[])
{
	if (!pipex || !argc | !argv)
		return (-1);
	if (pipex->here_doc)
		return (pipe_io_here_doc(argv[2], argv[argc - 1], pipex->io_fds));
	else if (!pipex->here_doc)
		return (pipe_io(argv[1], argv[argc - 1], pipex->io_fds));
	else
		return (-1);
}
