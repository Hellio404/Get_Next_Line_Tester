/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarini <yfarini@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:02:12 by yfarini           #+#    #+#             */
/*   Updated: 2019/10/27 10:28:09 by yfarini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define CONTINUE_READING	2
# define SUCCESS	    1
# define END_OF_FILE    0
# define FAILED		    -1

# define MFD	1025

typedef unsigned char	t_bool;
# define TRUE 1
# define FALSE 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
t_bool	ft_join_and_free(char **line, char *buff_left);
t_bool	ft_new_line(char **line, char *buff_left, size_t i);
int		ft_process(char **line, char *buff_left, ssize_t size, t_bool is_read);
#endif
