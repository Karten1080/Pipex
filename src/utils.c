/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:27:15 by asmati            #+#    #+#             */
/*   Updated: 2025/10/28 13:08:33 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**get_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;
	int		i;

	if (!paths || !cmd)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (NULL);
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!command)
			return (NULL);
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	cleanup_and_exit(t_pipex *pip, char *cmd_path, int exit_code)
{
	if (cmd_path)
		free(cmd_path);
	free_array(pip->env_path);
	free_array(pip->cmd_args);
	exit(exit_code);
}

void	execute_cmd(char *cmd_str, char **envp)
{
	t_pipex	pip;
	char	*cmd_path;

	pip.env_path = get_paths(envp);
	pip.cmd_args = ft_split(cmd_str, ' ');
	if (!pip.cmd_args || !pip.cmd_args[0])
	{
		free_array(pip.env_path);
		free_array(pip.cmd_args);
		ft_putendl_fd("Error: invalid command", STDERR_FILENO);
		exit(127);
	}
	cmd_path = NULL;
	if (pip.env_path)
		cmd_path = find_cmd_path(pip.env_path, pip.cmd_args[0]);
	if (!cmd_path)
	{
		ft_putstr_fd("Command not found: ", STDERR_FILENO);
		ft_putendl_fd(pip.cmd_args[0], STDERR_FILENO);
		cleanup_and_exit(&pip, cmd_path, 127);
	}
	execve(cmd_path, pip.cmd_args, envp);
	perror("execve");
	cleanup_and_exit(&pip, cmd_path, 1);
}
