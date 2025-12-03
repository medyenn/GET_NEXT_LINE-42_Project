/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:09:53 by mennih            #+#    #+#             */
/*   Updated: 2025/11/30 18:09:43 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 75
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*extract_line(char **line_ptr);
char	*form_line(int fd, char *line);
char	*get_next_line(int fd);
void	fill_line(char *temp, char *line, int *i, int j);
char	*ft_free(char *buf1, char *buf2);
int		length_of_line(char *line);
int		check_line(char *buff);
char	*join_line(char *line, char *buffer);
char	*update_line(char *line, int j);
char	*duplicate_line(char *buff);

#endif
