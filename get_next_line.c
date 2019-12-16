/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:15:33 by jherrald          #+#    #+#             */
/*   Updated: 2019/12/16 20:14:28 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		x;
	char	*new;

	new = NULL;
	x = 0;
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[x])
	{
		new[x] = s1[x];
		x++;
	}
	new[x] = '\0';
	return (new);
}

char	*ft_strjoin(char **s1, const char *s2)
{
	int		x;
	int		y;
	char	*new;

	if (*s1 == NULL && s2 == NULL)
		return (NULL);
	x = ft_strlen(*s1);
	y = ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * (x + y + 1))))
		return (NULL);
	ft_memmove(new, *s1, x);
	y = -1;
	while (s2[++y] != '\0')
		new[y + x] = s2[y];
	new[y + x] = '\0';
	free(*s1);
	return (new);
}

int		check_stat(char **line, char temp[BUFFER_SIZE + 1], char *stat)
{
	int x;

	if (check_nl(stat, '\n'))
	{
		if (!(*line = ft_strjoin(line, stat)))
			return (ft_free(&stat, -1));
		free(stat);
		stat = NULL;
	}
	else
	{
		x = -1;
		while (stat[++x] != '\n' && stat[x])
			temp[x] = stat[x];
		temp[x] = '\0';
		if (!(*line = ft_strjoin(line, temp)))
			return (ft_free(&stat, -1));
		ft_memmove(stat, &stat[x + 1], ft_strlen(stat) - x);
		return (1);
	}
	return (0);
}

int		mini_gnl(char **line, char *buf, char *temp, char **stat)
{
	int x;

	if (check_nl(buf, '\n'))
	{
		if (!(*line = ft_strjoin(line, buf)))
			return (ft_free(stat, -1));
	}
	else
	{
		x = -1;
		while (buf[++x] != '\n' && buf[x])
			temp[x] = buf[x];
		temp[x] = '\0';
		if (!(*line = ft_strjoin(line, temp)))
			return (ft_free(stat, -1));
		if (!(*stat = ft_strdup(&buf[x + 1])))
			return (ft_free(stat, -1));
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	char			temp[BUFFER_SIZE + 1];
	int				x;
	static char		stat[OPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || !line || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strdup("");
	if (stat[fd] && *stat[fd])
		if ((x = check_stat(line, temp, stat[fd])) != 0)
			return (x);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((x = mini_gnl(line, buf, temp, &stat[fd])) != 0)
			return (x);
	}
	return (ret);
}
