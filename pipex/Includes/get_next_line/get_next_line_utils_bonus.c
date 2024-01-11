/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:00:56 by udumas            #+#    #+#             */
/*   Updated: 2023/11/19 17:22:28 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		return (0);
	}
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_isnewline(char *stash)
{
	int	i;

	i = 0;
	if (stash == NULL)
		return (-1);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_cpy_and_clean(char *buffer, char *stash)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(stash) + 1));
	if (stash != NULL)
	{
		while (stash[i])
		{
			join[i] = stash[i];
			i++;
		}
		free(stash);
	}
	while (buffer[j])
		join[i++] = buffer[j++];
	join[i] = '\0';
	return (join);
}

void	ft_clean(char **stash)
{
	char	*new;
	int		i;
	int		j;

	if (!(*stash))
		return ;
	if (ft_isnewline(*stash) == -1 && (*stash)[0] == '\0')
	{
		free(*stash);
		return ;
	}
	if (ft_isnewline(*stash) == -1)
		i = ft_strlen(*stash);
	else
	{
		i = ft_isnewline(*stash);
	}
	new = malloc(sizeof(char) * (ft_strlen(*stash) - i + 1));
	j = 0;
	while ((*stash)[i++] != '\0')
		new[j++] = (*stash)[i];
	new[j] = '\0';
	free(*stash);
	*stash = new;
}

void	ft_cpy_line(char *stash, char **line)
{
	int	i;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			(*line)[i] = stash[i];
			i++;
			break ;
		}
		(*line)[i] = stash[i];
		i++;
	}
	if (stash[0] != '\0')
		(*line)[i] = '\0';
	else
		(*line)[0] = '\0';
}
