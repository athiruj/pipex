/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hdoc_fds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:47:44 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/31 23:41:40 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static char	*initialize_hdoc(char *eof);

static char	*append_to_hdoc(char *here_doc_remain, char *line);

static char	*read_hdoc(char *eof);

static int	prepare_hdoc(int *fd, char *eof);

/*
 *	setup_hdoc_fds() set up here_doc/out file descriptor
 *	Return 0 on success and return 1 when fail
 */
int	setup_hdoc_fds(
	int *infile_fd,
	int *outfile_fd,
	char *outfile,
	char *eof
	)
{
	if (!infile_fd || !outfile_fd || !outfile || !eof)
		return (1);
	if (prepare_hdoc(infile_fd, eof) == -1)
		return (1);
	*outfile_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, \
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (*outfile_fd == -1)
	{
		close(*infile_fd);
		perror("pipex");
		return (1);
	}
	return (0);
}

/*
 *	prepare_hdoc() prepare file descriptor for here_doc and store in fd
 *	Return file desscriptor and return -1 when fail
 */
static int	prepare_hdoc(int *fd, char *eof)
{
	int		fds[2];
	char	*here_doc;

	if (!fd || !eof)
		return (-1);
	if (pipe(fds) == -1)
	{
		perror("create pipe failed");
		return (-1);
	}
	*fd = fds[0];
	here_doc = read_hdoc(eof);
	if (here_doc)
	{
		write(fds[1], here_doc, ft_strlen(here_doc));
		free(here_doc);
	}
	if (close(fds[1]) == -1)
	{
		perror("close pipe failed");
		return (-1);
	}
	return (*fd);
}

/*
 *	read_hdxoc() read line by line use get_next_line()
 *	Return address of char from here_doc and return NULL when fail
 */
char	*read_hdoc(char *eof)
{
	char	*here_doc;
	char	*line;

	if (!eof)
		return (NULL);
	line = initialize_hdoc(eof);
	if (!line)
		return (NULL);
	if (*line == '\0')
		return (line);
	here_doc = (char *)malloc(sizeof(char));
	while (here_doc && ft_strcmp(line, eof) != '\n')
	{
		here_doc = append_to_hdoc(here_doc, line);
		line = get_next_line(0);
		if (!line)
		{
			free(here_doc);
			return (NULL);
		}
	}
	free(line);
	return (here_doc);
}

/*
 *	initialize_hdoc() get first line use get_next_line() and verification
 *	Return line from get_next_line() and return NULL when fail
 */
static char	*initialize_hdoc(char *eof)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		return (NULL);
	if (ft_strcmp(line, eof) == '\n')
	{
		free(line);
		return ((char *)ft_calloc(1, sizeof(char)));
	}
	return (line);
}

/*
 *	append_to_hdoc() append here_doc previous line and new line
 *	Return here_doc with new line and return NULL when fail
 */
static char	*append_to_hdoc(char *here_doc_remain, char *line)
{
	char	*here_doc;

	here_doc = ft_strjoin(here_doc_remain, line);
	free(here_doc_remain);
	if (!here_doc)
		return (NULL);
	free(line);
	return (here_doc);
}
