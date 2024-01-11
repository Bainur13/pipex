/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:20:50 by udumas            #+#    #+#             */
/*   Updated: 2023/11/19 17:28:37 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	ft_extract_from_file(char **stash, int fd);
void	ft_extract_from_stash(char **line, char *stash);

char	*ft_cpy_and_clean(char *buffer, char *stash);
size_t	ft_strlen(const char *str);
int		ft_isnewline(char *stash);
void	ft_clean(char **stash);
void	ft_cpy_line(char *stash, char **line);
#endif