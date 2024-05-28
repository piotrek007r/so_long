/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:21:15 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/24 17:21:33 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(int fd, char *buffer, char *reminder)
{
	int		bytes_read;
	char	*temp;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!reminder)
			reminder = ft_strdup("");
		temp = reminder;
		reminder = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (reminder);
}

static char	*splitreminder(char *line)
{
	char	*reminder;
	size_t	nlindex;

	nlindex = 0;
	while (line[nlindex] != '\n' && line[nlindex] != '\0')
		nlindex++;
	if (line[nlindex] == 0 || line[1] == 0)
		return (NULL);
	reminder = ft_substr(line, nlindex + 1, ft_strlen(line) - nlindex);
	if (*reminder == 0)
	{
		free(reminder);
		reminder = NULL;
	}
	line[nlindex + 1] = '\0';
	return (reminder);
}

char	*get_next_line(int fd)
{
	static char		*reminder;
	char			*buffer;
	char			*line;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (NULL);
	}
	line = reader(fd, buffer, reminder);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	reminder = splitreminder(line);
	return (line);
}

// int main()
// {
// 	int fd;
// 	int counter;

// 	fd = open("test.txt", O_RDONLY);
// 	counter = 0;
// 	while (counter < 3)
// 	{
// 		// printf("%i-", counter+1);
// 		printf("%i-FINAL OUTPUT %s\n\n", counter + 1, get_next_line(fd));
// 		counter++;
// 	}
// 	//free(reminder);
// 	close(fd);
// }
