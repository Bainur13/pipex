/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:02:03 by udumas            #+#    #+#             */
/*   Updated: 2024/02/08 12:02:24 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

char	*take_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

void	ft_free_char_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*add_slash(char *cmd1)
{
	int		i;
	char	*cmd_slash;

	i = 0;
	while (cmd1[i])
		i++;
	cmd_slash = malloc(sizeof(char) * i + 2);
	i = 0;
	while (cmd1[i])
	{
		cmd_slash[i] = cmd1[i];
		i++;
	}
	cmd_slash[i] = '/';
	cmd_slash[i + 1] = '\0';
	return (cmd_slash);
}

void	handle_error(int err, char *msg, int ac)
{
	if (err == -1)
	{
		perror(msg);
		exit(EXIT_FAILURE);
	}
	if (ac != 5 && err == -50000)
	{
		ft_printf("Error: Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
}

int	open_fd(int status, char **av, int ac)
{
	int	fd;

	fd = 0;
	if (status == 1)
	{
		fd = open(av[1], O_RDWR, 0777);
		handle_error(fd, av[1], 0);
	}
	else if (status == 2)
	{
		fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		handle_error(fd, av[ac - 1], 0);
	}
	return (fd);
}
