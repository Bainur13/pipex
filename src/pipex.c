/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:56:54 by udumas            #+#    #+#             */
/*   Updated: 2024/09/24 14:46:14 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	pipe_chain(char **env, char *av, int fd_out)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		handle_error(-1, "pipe", 0);
	id = fork();
	handle_error(id, "fork", 0);
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd_out);
		exec_command(av, env);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
}

int	exec_command(char *command, char **env)
{
	char	*instruct;

	instruct = check_valid_command(command, take_path(env));
	if (instruct == NULL)
	{
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (0);
	}
	else
	{
		execve(instruct, ft_split(command, ' '), env);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	last_pipe(char **env, char *av, int fd_out)
{
	int	id;
	int status;

	id = fork();
	handle_error(id, "fork", 0);
	if (id == 0)
	{
		dup2(fd_out, 1);
		close(fd_out);
		exec_command(av, env);
		exit(EXIT_FAILURE);
	}
	close(fd_out);
	waitpid(id, &status, 0);
	close (0);
	while (wait(NULL) > 0)
		continue ;
	close (0);
}

int	main(int ac, char **av, char **env)
{
	int	fd_in;
	int	fd_out;
	int	i;

	handle_error(-50000, NULL, ac);
	i = 2;
	fd_in = open_fd(1, av, ac);
	fd_out = open_fd(2, av, ac);
	dup2(fd_in, 0);
	close(fd_in);
	pipe_chain(env, av[i++], fd_out);
	last_pipe(env, av[i], fd_out);
	return (0);
}

char	*check_valid_command(char *cmd, char *path)
{
	char	**path_split;
	char	**cmd_split;
	char	*temp;
	int		i;

	i = 0;
	if (path == NULL)
		return (NULL);
	cmd_split = ft_split(cmd, ' ');
	if (access(cmd_split[0], F_OK | X_OK) == 0)
		return (ft_free_char_tab(cmd_split), ft_strdup(cmd));
	path_split = ft_split(path + 5, ':');
	while (path_split[i])
	{
		temp = add_slash(path_split[i]);
		path = ft_strjoin(temp, cmd_split[0]);
		free(temp);
		if (access(path, F_OK | X_OK) == 0)
			return (ft_free_char_tab(path_split), ft_free_char_tab(cmd_split),
				path);
		free(path);
		i++;
	}
	path = NULL;
	return (ft_free_char_tab(path_split), ft_free_char_tab(cmd_split), path);
}
