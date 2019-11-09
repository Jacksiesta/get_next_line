/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:37:04 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/09 22:47:51 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ** This function appends a single line into our line variable. We do this by
 * ** finding the length of the line. If at index len, the character is a newline,
 * ** we save the string into line up to the length found. Then we readjust the
 * ** stored data (**s) by creating a temporary string that stored the rest of data
 * ** after the newline. We free the stored data to update it to the current
 * ** address because we already append a line from it. This is done by freeing *s
 * ** and setting it equal to the temporary string that stored the remaining data.
 * ** At any point when we reach the end of the file, we free the memory used to
 * ** track our location in *s because it is not needed anymore.
 * */

int		len_line(char *s, char **line)
{
	size_t		len;
	size_t		size_whole_line;
	char		*temp;

	size_whole_line = 0;
	while (*s++)
		size_whole_line++;
	len = 0;
	while (s[len] != '\0' || *s[len] != '\n')
		len++;
	if (s[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		*temp = ft_substr(*s, len + 1, size_whole_line);
		free(*s);
		*s = temp;
		if (*s[0] == '\0')
			free(*s);
	}			
	else
	{
		*line = ft_substr(*s, 0, len);
		free(*s);
	}
	return (1);
}



/*
 * ** This is a helper function created to output the results after all the other
 * ** cases are taken care of in get_next_line. For example, if ret is less than 0,
 * ** then return -1 since an error occurred. If the reading is completed, return a
 * ** 0. Else, go to appendline function to return 1 and save the line read at the
 * ** current address of the static variable stored.
 * */ 




/*
 * ** The get_next_line function reads a file and returns the line ending with a
 * ** newline character from a file descriptor. A static variable is used, so that
 * ** whenever get_next_line is called, it remembers the previous function call.
 * ** When get_next_line is first called, we check to see if our static variable
 * ** **s is empty. If it is, we allocate memory for it using our buff string.
 * ** In the loop, we will continue to read more of the line and join them together
 * ** using a temporary string. This temporary string will replace the stored data
 * ** each iteration so that we can keep track of how much is read and delete
 * ** the previous stored data. This is needed because we are only reading so many
 * ** n-bytes at a time decided by our BUFFER_SIZE. If we read at each iteration
 * ** without freeing memory, then we would have memory leaks. The loop breaks when
 * ** a newline is encountered. Finally, we call output function to check what
 * ** should be returned.
 * */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	int		res;

	if (fd < 0 || !line)
		return (-1);
	while ((res = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[res] = '\0';


	}		
}
