/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:57:21 by udumas            #+#    #+#             */
/*   Updated: 2024/02/08 12:02:55 by udumas           ###   ########.fr       */
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
void	pipe_chain(char **env, char *av, int fd_out);
int		exec_command(char *command, char **env);
void	handle_error(int err, char *msg, int ac);
int		open_fd(int status, char **av, int ac);
#endif