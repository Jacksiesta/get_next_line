/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:00:28 by jherrald          #+#    #+#             */
/*   Updated: 2019/12/17 18:01:09 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	char	*line;
	int		nb_line;
	int		fd;
	int		fd2;
	int		fd3;

	if (ac < 3)
		return (0);
	nb_line = 1;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		printf("le fichier n'existe pas.");
	if ((fd2 = open(av[2], O_RDONLY)) == -1)
		printf("le fichier n'existe pas.");
	if ((fd3 = open(av[3], O_RDONLY)) == -1)
		printf("le fichier n'existe pas.");
	line = NULL;
	int ret = 0;
	while ((ret = get_next_line(fd, &line)) > 0 && nb_line)
	{
		printf("line[%d]: %s\n", nb_line, line);
		free(line);
		line = NULL;
		ret = get_next_line(fd2, &line);
		printf("line[%d]: %s\n", nb_line, line);
		free(line);
		line = NULL;
		ret = get_next_line(fd3, &line);
		printf("line[%d]: %s\n", nb_line, line);
		free(line);
		nb_line++;
	}
	printf("line[%d]: %s\n", nb_line, line);
	free(line);
	line = NULL;
	ret = get_next_line(fd2, &line);
	printf("line[%d]: %s\n", nb_line, line);
	free(line);
	line = NULL;
	ret = get_next_line(fd3, &line);
	printf("line[%d]: %s\n", nb_line, line);
	free(line);
	//	system("leaks a.out");
}

	//int	main(void)
	//{
	//	char	*line;
	//	int		nb_line;
	//	int		fd;
	//	int		ret;
	//
	//	nb_line = 1;
	//	if ((fd = open("test.c", O_RDONLY)) == -1)
	//		printf("erreur dans le fichier");
	//	while ((ret = get_next_line(fd, &line)) > 0)
	//	{
	//		printf("line read is : [%d] %s\n", nb_line, line);
	//		nb_line++;
	//		free(line);
	//	}
	//	printf("line read is : [%d] %s\n", nb_line, line);
	//	printf("%d\n", ret);
	//	free(line);
	//	system("leaks a.out")
	//}
