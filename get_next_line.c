/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:04:47 by clvicent          #+#    #+#             */
/*   Updated: 2022/05/12 18:45:59 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*res;
	static char	*stc;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 1024)
		return (NULL);
	if (!stc)
	{
		stc = malloc(1);
		if (!stc)
			return (NULL);
		stc[0] = '\0';
	}
	res = ft_new_line(stc, fd);
	return (res);
}

char	*ft_new_line(char *stc, int fd)
{
	char	*line;

	if (get_index(stc) != -1)
	{
		line = ft_pull(stc);
		stc = ft_clear_static(stc);
		return (line);
	}
	stc = ft_read(fd, stc);
	line = ft_pull(stc);
	stc = ft_clear_static(stc);
	return (line);
}

char	*ft_pull(char *stc)
{
	char	*line;
	if (get_index(stc) == -1)
		line = ft_substr(stc, 0, ft_strlen(stc));
	else
		line = ft_substr(stc, 0, get_index(stc) + 1);
	return (line);
}

char	*ft_clear_static(char *stc)
{
	char	*line;

	line = ft_strdup(&stc[get_index(stc) + 1]);
	free(stc);
	return (line);
}

char	*ft_read(int fd, char *stc)
{
	int		i;
	char	*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	i = 1;
	while (i > 0 && get_index(stc) != -1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		stc = ft_strjoin(stc, buf);
	}
	free(buf);
	return (stc);
}
