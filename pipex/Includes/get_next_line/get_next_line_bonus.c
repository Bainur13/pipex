/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:50:11 by udumas            #+#    #+#             */
/*   Updated: 2023/11/19 17:22:56 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stash[2048];
	char		*line;

	line = NULL;
	if (fd < 0 || read(fd, line, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_extract_from_file(&stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	ft_extract_from_stash(&line, stash[fd]);
	ft_clean(&stash[fd]);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

void	ft_extract_from_file(char **stash, int fd)
{
	int		readed;
	char	*buffer;

	readed = 1;
	while (ft_isnewline(*stash) == -1 || (stash == NULL && readed != 0))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == 0)
		{
			free(buffer);
			return ;
		}
		buffer[readed] = '\0';
		*stash = ft_cpy_and_clean(buffer, *stash);
		if (!*stash)
			return ;
		free(buffer);
	}
}

void	ft_extract_from_stash(char **line, char *stash)
{
	int	i;

	if (stash == NULL)
		return ;
	i = 0;
	if (ft_isnewline(stash) == -1)
		i = ft_strlen(stash);
	else
		i = ft_isnewline(stash) + 1;
	*line = malloc(sizeof(char) * (i + 1));
	i = 0;
	ft_cpy_line(stash, line);
}
