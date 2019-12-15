/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:18:33 by jherrald          #+#    #+#             */
/*   Updated: 2019/12/15 18:54:49 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int		len_line(char *s, char **line)
{
	size_t		len;
	size_t		size_whole_line;
	char		*temp;

	size_whole_line = 0;
	while(*s++)
		size_whole_line++;
	len = 0;
	while(s[len] != '\0' || *s[len] != '\n')
		len++;
	if (s[len] == '\n')
	{
		*line = ft_substr(s, 0, len);
		*temp = ft_strdup((char const)*s);
		free(s);
		*s = temp;
		if (s[len] == '\0')
			ft_strdel(*s);
	}
	else
	{
		*line = ft_substr(*s, 0, len);
		ft_strdel(*s);
	}
	return (1);
}

/*
** Ceci est un test pour github
*/

int		result(char **s, char **line, int res, int fd)
{
	if (res < 0)
		return (-1);
	if (res == 0) //reading completed
		return (0);
	return (len_line(&s, line)); //got to ft who returns 1 + save the line read at current address of static var stored
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		x[fd];
	char			*temp;
	int				res;

	if (fd < 0 || !line)
		return (-1);
	while (res = read(fd, buff, BUFFER_SIZE))
	{
		buff[res] = '\0';
		if (x[fd] == NULL) //check if pointer is empty
			x[fd] = ft_strdup(buff); // malloc 
		else
			temp = ft_strjoin(x[fd], buff);
			free(x[fd]);
			x[fd] = temp;
		if (ft_strchr(x[fd], '\n'))
			break;
	}
	if (res < 0)
		return (-1);
	if (res == 0)
		return (0);
	return (result(*x, *line, res, fd));
}
		
