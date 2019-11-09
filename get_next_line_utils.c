/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:21:36 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/09 22:47:53 by jherrald         ###   ########.fr       */
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

char	*ft_strndup(const char *s, int n)
{
	int		x;
	char 	*new;
	
	if (!(new = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	x = 0;
	while (x < n)
	{
		new[x] = s[x];
		x++;
	}
	new[x] = '\0';
	return (new);
}
