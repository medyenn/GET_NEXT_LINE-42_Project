/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:37:59 by mennih            #+#    #+#             */
/*   Updated: 2025/11/30 10:19:59 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd1 = open("get_next_line.h", O_RDONLY);
	int fd2 = open("get_next_line.h", O_RDONLY);
	char *s1 = get_next_line(fd1);
//	char *s2 = get_next_line(fd2);
	while (s1 )//&& s2)
	{
		printf("%s", s1);
		//printf("%s", s2);
		s1 = get_next_line(fd1);
		//s2 = get_next_line(fd2);
	}
	return (0);
}