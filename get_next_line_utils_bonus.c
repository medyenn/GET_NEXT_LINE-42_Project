/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:31:57 by mennih            #+#    #+#             */
/*   Updated: 2025/11/29 22:32:20 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *buf1, char *buf2)
{
	free(buf1);
	buf1 = NULL;
	return (buf2);
}

int	length_of_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
		i++;
	return (i);
}

char	*update_line(char *line, int j)
{
	int		i;
	int		len;
	char	*temp;

	if (!line)
		return (NULL);
	len = length_of_line(line);
	if (len == j)
		return (ft_free(line, NULL));
	temp = malloc((len - j) + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (line[j + i])
	{
		temp[i] = line[j + i];
		i++;
	}
	temp[i] = '\0';
	free(line);
	return (temp);
}

char	*duplicate_line(char *buffer)
{
	int		len;
	int		i;
	char	*temp;

	len = length_of_line(buffer);
	temp = malloc(len + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*join_line(char *line, char *buffer)
{
	char	*temp;
	int		len1;
	int		len2;
	int		i;

	if (!line)
		return (duplicate_line(buffer));
	len1 = length_of_line(line);
	len2 = length_of_line(buffer);
	temp = malloc(len1 + len2 + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (line[i])
	{
		temp[i] = line[i];
		i++;
	}
	i = 0;
	while (buffer[i])
	{
		temp[len1 + i] = buffer[i];
		i++;
	}
	temp[len1 + len2] = '\0';
	return (ft_free(line, temp));
}
