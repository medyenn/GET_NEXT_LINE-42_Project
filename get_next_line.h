/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:09:53 by mennih            #+#    #+#             */
/*   Updated: 2025/11/27 21:22:06 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 75
# endif

int		check_line(char *buff);
char	*join_line(char *line, char *buff);
char	*update_line(char *line, int start, int len);

#endif
