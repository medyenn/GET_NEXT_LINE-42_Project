/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 08:42:46 by mennih            #+#    #+#             */
/*   Updated: 2025/11/30 10:17:30 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*extract_line(char **line_ptr)
{
	char	*temp;
	char	*line;
	int		i;
	int		j;
	int		n;

	line = *line_ptr;
	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	n = 1;
	if (line[i] == '\n')
		n = 2;
	temp = malloc(i + n);
	if (!temp)
		return (NULL);
	j = 0;
	while (j < i)
	{
		temp[j] = line[j];
		j++;
	}
	if (line[j] == '\n')
		temp[j++] = '\n';
	temp[j] = '\0';
	*line_ptr = update_line(line, j);
	return (temp);
}

char	*form_line(int fd, char *line)
{
	char	*buffer;
	int		n;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	n = read(fd, buffer, BUFFER_SIZE);
	while (n > 0)
	{
		buffer[n] = '\0';
		line = join_line(line, buffer);
		if (!check_line(line))
		{
			free(buffer);
			return (line);
		}
		n = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (n < 0)
		return (ft_free(line, NULL));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (check_line(line) == 0)
		return (extract_line(&line));
	line = form_line(fd, line);
	if (!line)
		return (NULL);
	return (extract_line(&line));
}
