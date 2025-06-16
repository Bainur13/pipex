/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:46:09 by udumas            #+#    #+#             */
/*   Updated: 2024/05/16 15:06:03 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

void	pipe_chain(char **env, char *av, int fd_out, int ac)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		handle_error(-1, "pipe", 0);
	id = fork();
	handle_error(id, "fork", 0);
	if (id == 0)
	{
		fd_out = open_fd(2, av, ac);
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
