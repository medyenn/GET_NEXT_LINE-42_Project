/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:56:52 by mennih            #+#    #+#             */
/*   Updated: 2025/11/27 21:34:50 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*join_line(char *line, char *buff)
{
	char	*temp;
	int		i;
	int		j;

	if (line == NULL)
		return (buff);
	i = 0;
	while (line[i])
		i++;
	temp = malloc(i + BUFF_SIZE + 1);
	if (!temp)
	{
		free(temp);
		return (NULL);
	}
	j = 0;
	while (j < i)
		temp[j] == line[j++];
	j = 0;
	while (j < BUFF_SIZE)
		temp[i + j] = buff[j++];
	temp[i + j] == '\0';
	return (line);
}

char	*update_line(char *line, int start, int len)
{
	char	*temp;
	int		i;

	temp = malloc(len + 1);
	if (!temp)
	{
		free(temp);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		temp[i] = line[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
