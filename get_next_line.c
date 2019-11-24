/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:15:33 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/24 22:39:24 by jherrald         ###   ########.fr       */
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

size_t	strlen(const char *str)
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
	x = strlen(s1); //len s1//
	y = strlen(s2); //len s2//
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
	if (!(new = (char *)malloc(sizeof(char) * (strlen(s1) + 1))))
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
	static char		*stat;

	if (*stat)
	{
		if (check_nl(stat, '\n')) // no '\n' in buf //
		{
			*line = ft_strdup(stat);
			printf("stat line is = %s\n", *line);
			return (0);
		}
		else if (check_nl(stat, '\n') == 0) // '\n' in buf //
		{
			*line = ft_strjoin(*line, stat);
			return (1);
		}
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		printf("nbr octet(s) lu(s) = %d\n", ret);
		buf[ret] = '\0';
		if (check_nl(buf, '\n')) // no '\n' in buf //
		{
			*line = ft_strjoin(*line, buf);
			printf("line is = %s\n", *line);
			printf("buf is = %s\n", buf);
		}
		else if (check_nl(buf, '\n') == 0) // '\n' in buf //
		{
			x = 0;
			while (buf[x] != '\n')
			{	
				temp[x] = buf[x];
				x++;
			}
			temp[x] = '\0';
			*line = ft_strjoin(*line, temp);
			printf("joined = %s\n", *line);
			printf("x = %d\n", x);
			y = 0;
			while (buf[x + 1] != '\0')
			{
				stat[y] = buf[x + 1];
				y++;
				x++;
			}
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

	nb_line = 0;
	if ((fd = open("test.c", O_RDONLY)) == -1)
		printf("erreur dans le fichier");
	while (get_next_line(fd, &line) > 0)
	{
		printf("line read is : [%d] %s\n", nb_line, line);
		nb_line++;
		free(*line);
	}	
}
