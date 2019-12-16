/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:19:50 by jherrald          #+#    #+#             */
/*   Updated: 2019/12/16 16:19:54 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		check_nl(char *s, char c);
size_t	ft_strlen(const char *str);
int		ft_free(char **stat, int ret);

#endif
