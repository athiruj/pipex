/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:10:09 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/20 14:29:09 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	prepare_io_pipes(t_pipex *pipex, int idx)
{
	// printf("%d, %d\n", idx, pipex->process);
	if (idx == 0)
	{
		fprintf(stderr,"stdin = %d, stdout = %d\n", pipex->io_fds[0], pipex->pipe_fds[0][1]); 
		if (dup2(pipex->io_fds[0], STDIN_FILENO) == -1
			|| dup2(pipex->pipe_fds[0][1], STDOUT_FILENO) == -1)
				return (-1);
	}
	else if (idx == pipex->process)
	{
		fprintf(stderr,"stdin = %d, stdout =%d\n", pipex->pipe_fds[idx - 1][0], pipex->io_fds[1]); 
		if (dup2(pipex->pipe_fds[idx - 1][0], STDIN_FILENO) == -1
			|| dup2(pipex->io_fds[1], STDOUT_FILENO) == -1)
			return (-1);
	}
	else
	{
		fprintf(stderr,"stdin = %d, stdout = %d\n", pipex->pipe_fds[idx - 1][0], pipex->pipe_fds[idx][1]); 
		if (dup2(pipex->pipe_fds[idx - 1][0], STDIN_FILENO) == -1
			|| dup2(pipex->pipe_fds[idx][1], STDOUT_FILENO) == -1)
			return (-1);
	}
	fprintf(stderr,"========================\n"); 
	return (0);
}

int	wait_process(pid_t *pids, int n_pipes)
{
	int	i;

	i = 0;
	while (i < n_pipes)
		if (waitpid(pids[i], NULL, 0))
			fprintf(stderr, "wait = %d\n", pids[i++]);

	return (0);
}

int	pipex_process(t_pipex *pipex, char **env)
{
	int		i;
	pid_t	pid;
	pid_t	*pids;

	// pipex->cmd_paths[0] = "/bin/cat";
	// pipex->cmd_paths[1] = "/usr/bin/wc";
	// pipex->cmd_paths[2] =  "/bin/cat";
	// pipex->cmds = {{"cat", "-e"},{"wc", "-l"},{"cat", "-e"}};

	i = 0;
	pids = (pid_t *)malloc(sizeof(pid_t) * (pipex->process + 1));
	while (i <= pipex->process)
	{
		pid = fork();
		if (pid < 0)
			return (-1);
		else if (pid == 0)
		{
			if (prepare_io_pipes(pipex, i))
				return (ft_puterror(PROGRAM, NULL, -1));
			close_except_fds(pipex, i);
			close_fds(pipex, i);
			fprintf(stderr, "\nchild process = %d %s %s\n\n", i, pipex->cmd_paths[i], pipex->cmds[i][0]);
			if (execve(pipex->cmd_paths[i], pipex->cmds[i], env))
			{

				return (-1);
			}
			fprintf(stdout, "============================================================\n");
			exit (0);
		}
		else if (pid > 0)
		{
			fprintf(stderr, "\nparent process = %d %d\n\n", i, pid);
			pids[i] = pid;
		}
		i++;
	}
	wait_process(pids, pipex->process);
	return (0);
}
