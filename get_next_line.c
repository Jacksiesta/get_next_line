/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:15:33 by jherrald          #+#    #+#             */
/*   Updated: 2019/12/09 20:55:04 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_nl(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (0); //'\n' in buf//
		s++;
	}
	return (1); //no '\n' in buf//
}

size_t	ft_strlen(const char *str)
{
	size_t x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int 	x;
	int 	y;
	char	*new;

	if (s1 == NULL && s2 == NULL)
		return (NULL);	
	x = ft_strlen(s1); //len s1//
	y = ft_strlen(s2); //len s2//
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (x + y + 1))))
	   return (NULL);
	y = -1;
	while (s1[++y] != '\0')
		new[y] = s1[y];
	y = -1;
	while (s2[++y] != '\0')
		new[y + x] = s2[y];
	new[y + x] = '\0';
	return (new);
}

char	*ft_strdup(const char *s1)
{
	int		x;
	char	*new;

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

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	char			temp[BUFFER_SIZE + 1];
	int				x;
	int				y;
	int				len;
	static char		*stat;

	if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(*line) + 1))))
		return (0);
	*line = "";
	x = -1;
	if (stat && *stat)
	{
		if (check_nl(stat, '\n')) // no '\n' in stat //
		{
			*line = ft_strdup(stat);
			stat = NULL;
		}
		else // '\n' in stat //
		{
			while (stat[++x] != '\n')
				temp[x] = stat[x];
			temp[x] = '\0';
			*line = ft_strjoin(*line, temp);
			len = ft_strlen(stat) - x;
			stat = ft_memmove(stat, &stat[x + 1], len);
			stat[ft_strlen(stat)] = '\0';
			return (1);
		}
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (check_nl(buf, '\n')) // no '\n' in buf //
			*line = ft_strjoin(*line, buf);
		else if (check_nl(buf, '\n') == 0) // '\n' in buf //
		{
			while (buf[++x] != '\n')
				temp[x] = buf[x];
			temp[x] = '\0';
			*line = ft_strjoin(*line, temp);
			y = -1;
			stat = ft_strdup(&buf[x + 1]);
			while (buf[x + 1] != '\0')
				stat[++y] = buf[x++ + 1];
			return (1);
		}
	}
	return (ret);
}

int main()
{
	char *line;
	int nb_line;
	int fd;

	nb_line = 1;
	if ((fd = open("test.c", O_RDONLY)) == -1)
		printf("erreur dans le fichier");
	while (get_next_line(fd, &line) > 0)
	{
		printf("line read is : [%d] %s\n", nb_line, line);
		nb_line++;
		free(line);
	}	
	printf("line read is : [%d] %s\n", nb_line, line);
}
