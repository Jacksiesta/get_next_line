/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:21:36 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/10 18:02:56 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		x;
	char				*new;
	size_t				lenght;

	if (!s)
		return (NULL);
	lenght = 0;
	while (s[lenght] != '\0')
		lenght++;
	if ((lenght - (size_t)start) < len)
		len = lenght - (size_t)start;
	if ((size_t)start > lenght;)
		len = 0;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	x = 0;
	while (len--)
	{
		new[x] = s[start + x];
		x++
	}
	new[x] = '\0';
	return (new);
}

char	*ft_strdup(const char *s)
{
	int		x;
	char 	*new;
	
	if (!(new = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	x = 0;
	while (s[x] != '\0')
	{
		new[x] = s[x];
		x++;
	}
	new[x] = '\0';
	return (new);
}

void	ft_strdel(char **c)
{
	if (c)
	{
		free(*c)
		*c = NULL;
	}
	return ;
}

char	*ft_strchr(const char *s, int c)
{
	int		x;

	x = 0;
	while (s[x])
	{
		if (s[x] == ((char)c)
			return ((char *)&s[x]);
		x++;
	}
	if (s[x] == (char)c)
		return ((char *)&s[x]);
	return (NULL);
}
