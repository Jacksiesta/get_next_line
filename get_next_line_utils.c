/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:50:15 by jherrald          #+#    #+#             */
/*   Updated: 2019/12/16 13:23:10 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			x;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!d && !s)
		return (NULL);
	if (d > s)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	else if (d < s)
	{
		x = -1;
		while (++x < len)
			d[x] = s[x];
	}
	return (dst);
}

int		check_nl(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (0);
		s++;
	}
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int		ft_free(char **stat, int ret)
{
	if (*stat)
	{
		free(*stat);
		*stat = NULL;
	}
	return (ret);
}
