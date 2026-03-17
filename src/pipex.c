/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:00:00 by asmati            #+#    #+#             */
/*   Updated: 2025/10/28 15:57:35 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_first_child(int *pipefd, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		close(pipefd[0]);
		close(pipefd[1]);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	execute_cmd(argv[2], envp);
}

void	handle_second_child(int *pipefd, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		close(pipefd[0]);
		close(pipefd[1]);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	execute_cmd(argv[3], envp);
}

void	handle_child_process(int *pipefd, char **argv, char **envp,
		int is_first)
{
	if (is_first)
		handle_first_child(pipefd, argv, envp);
	else
		handle_second_child(pipefd, argv, envp);
}

int	create_processes(int *pipefd, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	pid1 = fork();
	if (pid1 < 0)
		return (perror("fork"), 1);
	else if (pid1 == 0)
		handle_child_process(pipefd, argv, envp, 1);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("fork"), 1);
	else if (pid2 == 0)
		handle_child_process(pipefd, argv, envp, 0);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
