/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:49:00 by udumas            #+#    #+#             */
/*   Updated: 2024/01/09 11:33:46 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (0);
	}
	if (init_pipe1(env, av) == 0)
		return (0);
}

char	*check_valid_command(char *cmd, char *path)
{
	char	**path_split;
	char	**cmd_split;
	char	*temp;
	int		i;

	i = 0;
	cmd_split = ft_split(cmd, ' ');
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

int	init_pipe1(char **env, char **av)
{
	int	fd[2];
	int	id;
	int	fd_in;

	if (pipe(fd) == -1)
		handle_error(-1, "pipe");
	id = fork();
	handle_error(id, "fork");
	if (id == 0)
	{
		fd_in = open(av[1], O_RDONLY, 0777);
		handle_error(fd_in, av[1]);
		dup2(fd_in, 0);
		if (fd_in != -1)
			close(fd_in);
		dup2(fd[1], 1);
		close(fd[0]);
		exec_command(av[2], env);
	}
	else
	{
		wait(NULL);
		return (init_pipe2(env, av, fd));
	}
	return (1);
}

int	init_pipe2(char **env, char **av, int fd[2])
{
	int		id2;
	int		fd_out;

	dup2(fd[0], 0);
	id2 = fork();
	handle_error(id2, "fork");
	if (id2 == 0)
	{
		fd_out = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		handle_error(fd_out, "fd_out");
		dup2(fd_out, 1);
		close(fd[1]);
		if (fd_out != -1)
			close(fd_out);
		exec_command(av[3], env);
	}
	close_both(fd);
	return (1);
}

int	exec_command(char *command, char **env)
{
	char	*instruct;

	instruct = check_valid_command(command, take_path(env));
	if (instruct == NULL)
		ft_putstr_fd("Command not found\n", 2);
	else
		execve(instruct, ft_split(command, ' '), env);
	return (0);
}
