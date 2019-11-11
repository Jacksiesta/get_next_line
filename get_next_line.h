/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:38:15 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/11 16:41:14 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 32
# include <unistd.h>
# include <stdio.h>
# include <limits.h>


int		get_next_line(int fd, char **line);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void	ft_strdel(char **c);
char	*ft_strchr(const char *s, int c);
int		len_line(char *s, char **line);
int		result(char **s, char **linem int res, int fd);

#endif
