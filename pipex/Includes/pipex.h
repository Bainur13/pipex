/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:48:48 by udumas            #+#    #+#             */
/*   Updated: 2024/01/07 17:40:09 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

char	*take_path(char **env);
char	*check_valid_command(char *cmd1, char *path);
char	*add_slash(char *cmd1);
void	ft_free_char_tab(char **str);
int		init_pipe1(char **env, char **av);
int		init_pipe2(char **env, char **av, int fd[2]);
void	close_both(int fd[2]);
int		exec_command(char *command, char **env);
void	handle_error(int err, char *msg);

#endif