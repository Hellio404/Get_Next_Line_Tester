/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarini <yfarini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 04:46:25 by yfarini           #+#    #+#             */
/*   Updated: 2019/10/29 02:36:16 by yfarini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_bool	ft_check(ssize_t *size, t_bool *is_read, char **line, int fd)
{
	if (BUFFER_SIZE <= 0 || !line || read(fd, NULL, 0) != 0 || fd < 0)
		return (FALSE);
	if (!(*line = (char *)malloc(1)))
		return (FALSE);
	**line = 0;
	*size = 1;
	*is_read = TRUE;
	return (TRUE);
}

int		get_next_line(int fd, char **line)
{
	static char		buff_left[MFD][BUFFER_SIZE + 1] = {""};
	t_bool			is_read;
	ssize_t			size;
	int				holder;
	int a;
	if (ft_check(&size, &is_read, line, fd) == FALSE)
		return (FAILED);
	while (size > 0)
	{
		is_read = FALSE;
		if (!buff_left[fd][0])
		{
			size = read(fd, buff_left[fd], BUFFER_SIZE);
			buff_left[fd][size] = 0;
			is_read = TRUE;
		}
		if ((holder = ft_process(line, buff_left[fd],
		size, is_read)) != CONTINUE_READING)
			return (holder);
	}
	return (END_OF_FILE);
}
