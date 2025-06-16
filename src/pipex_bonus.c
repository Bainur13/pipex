/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:56:54 by udumas            #+#    #+#             */
/*   Updated: 2024/05/16 15:07:12 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

void	here_doc(char *limiter, int fd[2])
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		line = get_next_line(0, 1);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			close(fd[1]);
			close(fd[0]);
			get_next_line(0, 0);
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
}

void	launch_here_doc(char *limiter)
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
		here_doc(limiter, fd);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		wait(&id);
	}
}

void	last_pipe(char **env, char *av, int fd_out)
{
	int	id;

	id = fork();
	handle_error(id, "fork", 0);
	if (id == 0)
	{
		dup2(fd_out, 1);
		close(fd_out);
		exec_command(av, env);
		exit(EXIT_FAILURE);
	}
	else
		close(fd_out);
	while (wait(NULL) > 0)
		continue ;
}

int	main(int ac, char **av, char **env)
{
	int	fd_in;
	int	fd_out;
	int	i;

	if (!*env)
	{
		printf ("No ENV\n");
		exit(EXIT_FAILURE);
	}
	handle_error(-50000, NULL, ac);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		handle_error(-50001, NULL, ac);
		i = 3;
		fd_out = open_fd(0, av, ac);
		launch_here_doc(av[2]);
	}
	else
	{
		i = 2;
		fd_in = open_fd(1, av, ac);
		fd_out = open_fd(2, av, ac);
		dup2(fd_in, 0);
		close(fd_in);
	}
	while (i < ac - 2)
		pipe_chain(env, av[i++], fd_out, ac);
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
