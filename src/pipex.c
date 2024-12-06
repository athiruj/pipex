/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:41 by atkaewse          #+#    #+#             */
/*   Updated: 2024/12/06 12:09:17 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// int	pipex(int argc, char *argv[], char *env[]);
// int	initial_pipe(t_pipex *pipe, int argc, char *argv[], char *env[]);

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
	// if (pipex(argc, argv, env))
	// 	return (errno);
	return (0);
}

// int	pipex(int argc, char *argv[], char *env[])
// {
// 	t_pipex	pipex;

// 	if (initial_pipe(&pipex, argc, argv, env))
// 		return (errno);
// 	return (0);
// }

// int	initial_pipe(t_pipex *pipe, int argc, char *argv[], char *env[])
// {
// 	if (!ft_strcmp("here_doc", argv[1]))
// 	{
// 		pipe->here_doc = 1;
// 		pipe->pipes = argc - 5;
// 	}
// 	else
// 	{
// 		pipe->here_doc = 0;
// 		pipe->pipes = argc - 4;
// 		pipe->src_fd = open(argv[1], O_RDONLY);
// 		if (pipe->src_fd == -1)
// 			exit (ft_puterror("pipex: ", argv[1], errno));
// 	}
// 	pipe->dst_fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, \
// 	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
// 	if (pipe->dst_fd == -1)
// 		return (errno);
// 	pipe->cmds = (char **)malloc(sizeof(char *) * (pipe->pipes + 1));
// 	if (!pipe->cmds)
// 		return (errno);
// 	ft_memmove(pipe->cmds, argv + 2 + pipe->here_doc, \
// 	sizeof(char *) * (pipe->pipes + 1));

// 	return (0);
// }

// 	// while (*pipe->cmds)
// 	// 	printf("%s\n", *pipe->cmds++);
// // int	main(int argc, char *argv[], char *env[])
// // {
// // 	char *path[2] = {"/usr/bin/wc", "/bin/cat"};
// // 	char *cmd[3][6] = {{"wc", "-l", NULL, NULL, NULL, NULL},\
//  {"cat", "-e", NULL, NULL, NULL, NULL}};
// // 	int fds[2];
// // 	pid_t pid;
// // 	int in_fd = open("infile", O_RDONLY);
// // 	// int midr_fd = open("midfile", O_RDONLY);
// // 	// int midw_fd = open("midfile", O_CREAT | O_WRONLY | O_TRUNC , \ 1S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
// // 	int n;

// // 	if (pipe(fds) == -1)
// // 	{
// // 		perror("pipe fail");
// // 		return (errno);
// // 	}
// // 	int out_fd = open("outfile", O_CREAT | O_WRONLY | O_TRUNC , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
// // 	printf("%d %d\n", fds[0], fds[1]);
// // 	int i = 2;
// // 	while (i--){
// // 		pid = fork();
// // 		if (pid < 0)
// // 		{
// // 			perror("fork fail");
// // 			return (errno);
// // 		}
// // 		else if(pid == 0)
// // 		{
// // 			fprintf(stderr,"i = %d\n", i);
// // 			if (i == 1)
// // 			{
// // 				fprintf(stderr,"stdin i = 1 %d\n", in_fd);
// // 				fprintf(stderr,"stdout i = 1 fd %d\n", fds[1]);
// // 				dup2(in_fd, STDIN_FILENO);
// // 				close(fds[0]);	
// // 				dup2(fds[1], STDOUT_FILENO);
// // 			}
// // 			else
// // 			{
// // 				fprintf(stderr,"stdin i = 0 fd %d\n", fds[0]);
// // 				fprintf(stderr,"stdout i = 0 fd %d\n", out_fd);
// // 				close(fds[1]);	
// // 				dup2(fds[0], STDIN_FILENO);
// // 				dup2(out_fd, STDOUT_FILENO);
// // 			}
// // 			if (execve(path[i], cmd[i], env) == -1)
// // 			{
// // 				perror("fork fail");
// // 				return (errno);
// // 			}
// // 		}
// // 	}
// // 	close(fds[0]);
// // 	close(fds[1]);
// // 	if (waitpid(pid, &n, 0) == -1)
// // 	{
// // 			perror ("wait fail");
// // 			exit(0);
// // 	}
// // 	return (errno);
// // }

// // static char	**px_get_path_dirs(char *env[], int *i)
// // {
// // 	*i = -1;
// // 	while (env[++*i] && ft_strncmp(env[*i], "PATH=", 5) != 0)
// // 	{
// // 		continue ;
// // 	}
// // 	if (!env[*i] || ft_strncmp(env[*i], "PATH=", 5) != 0)
// // 		return (ft_split("", ':'));
// // 	return (ft_split(env[*i] + 5, ':'));
// // }

// // // #include <stdio.h>

// // int main (int argc, char *argv[], char *env[])
// // {
// // 	char **path;
// // 	int i = 0;
// // 	int *ptr_i = &i;
// // 	int j = 0;
// // 	path = px_get_path_dirs(env, ptr_i);

// // 	while (env[j])
// // 		printf("%s\n", env[j++]);
// // 	printf("================================");
// // 	while (*path)
// // 		printf("%s\n", *path++);
// // 	return (0);
// // }
// // void forkexample()
// // {
// //     pid_t p;
// //     p = fork();
// //     printf("%d pids = %d\n", p, getpid());
// //     if(p<0)
// //     {
// //     	perror("fork fail");
// //     	exit(1);
// //     }
// // 	// child process because return value zero
// //     else if ( p == 0)
// //         printf("Hello from Child!\n");

// //     // parent process because return value non-zero.
// //     else
// //         printf("Hello from Parent!\n");
// // }
// // int main()
// // {
// // 	pid_t i;
// // 	i = fork();
// // 	if (i == 0)
// // 		printf("parent procress\n");
// // 	else if (i != 0)
// // 		printf("child procress 1rd\n");
// //     return (0);
// // }

// // #include <string.h>

// // int main() {
// //     int pipefd[2];
// // 	int i;
// // 	int status;
// //     pid_t pid;
// //     char buffer[128];
// // 	i = 2;
// //     if (pipe(pipefd) == -1) {
// //         perror("pipe");
// //         return 1;
// //     }

// // 	write(1, "pre fork!!!!\n", 14);
// // 	while (i--)
// // 	{
// //     	fprintf(stdout, "fork!!!! %d %d\n", i, (pid = fork()));
// //     	if (pid < 0) {
// //     	    perror("fork");
// //     	    return 1;
// //     	}
// // 		if (pid == 0) {
// //     	    close(pipefd[0]); // ปิด read end
// //     	    printf("Here children process %d\n", pid);
// //     	    const char *message = "Hello from child!";
// //     	    write(pipefd[1], message, strlen(message) + 1);
// //     	    close(pipefd[1]); // ปิด write end
// //     	} else {
// //     	    close(pipefd[1]); // ปิด write end
// //     	    read(pipefd[0], buffer, sizeof(buffer));
// // 			waitpid(pid, &status, 0);
// //     	    printf("Parent received: %s %d\n", buffer, pid);
// //     	    close(pipefd[0]); // ปิด read end
// //     	}
// // 	}

// //     return 0;
// // }

// // #include <stdio.h>

// // int main ()
// // {
// // 	int	status;

// // 	status = access("/bin/ls", F_OK);
// // 	if (status == -1)
// // 		fprintf(stderr, "access fail %d", status);
// // 	else
// // 		fprintf(stdout, "access complete %d", status);
// // 	return (0);
// // }
