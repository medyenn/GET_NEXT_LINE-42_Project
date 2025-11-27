/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:00:38 by mennih            #+#    #+#             */
/*   Updated: 2025/11/27 22:02:26 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*form_line(int fd, char *line)
{
	char	buff[BUFF_SIZE];

	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (NULL);
	while (read(fd, buff, BUFF_SIZE))
	{
		buff[BUFF_SIZE] = '\0';
		line = join_line(line, buff);
		if (check_line(buff) == 0)
			return (line);
	}
	return (line);
}

static char	*extract_line(char *line)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (line[i])
		i++;
	temp = malloc(i + 2);
	if (!temp)
	{
		free(temp);
		return (NULL);
	}
	j = 0;
	while (j < i && line[j] != '\n')
	{
		temp[j] = line[j];
		j++;
	}
	temp[j] = '\n';
	temp[j + 1] = '\0';
	line = update_line(line, j + 1, i - j);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*result;

	line = form_line(fd, line);
	if (!line)
		return (NULL);
	result = extract_line(line);
	return (result);
}





#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("get_next_line.h", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
