/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:27:15 by asmati            #+#    #+#             */
/*   Updated: 2025/09/29 00:00:00 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include "../libs/Libft/libft.h"
# include "../libs/PRINTF/ft_printf.h"

typedef struct s_pipex
{
	char	**env_path;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

/* main.c */
int		main(int argc, char **argv, char **envp);

/* pipex.c */
void	handle_first_child(int *pipefd, char **argv, char **envp);
void	handle_second_child(int *pipefd, char **argv, char **envp);
void	handle_child_process(int *pipefd, char **argv, char **envp,
			int is_first);
int		create_processes(int *pipefd, char **argv, char **envp);

/* utils.c */
char	**get_paths(char **envp);
char	*find_cmd_path(char **paths, char *cmd);
void	execute_cmd(char *cmd, char **envp);
void	free_array(char **array);
void	cleanup_and_exit(t_pipex *pip, char *cmd_path, int exit_code);

#endif