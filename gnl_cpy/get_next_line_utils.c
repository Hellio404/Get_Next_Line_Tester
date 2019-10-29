/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarini <yfarini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 08:46:28 by yfarini           #+#    #+#             */
/*   Updated: 2019/10/28 15:06:30 by yfarini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (!*(str + 1))
			return (i + 1);
		if (!*(str + 2))
			return (i + 2);
		if (!*(str + 3))
			return (i + 3);
		if (!*(str + 4))
			return (i + 4);
		if (!*(str + 5))
			return (i + 5);
		if (!*(str + 6))
			return (i + 6);
		if (!*(str + 7))
			return (i + 7);
		i += 8;
		str += 8;
	}
	return (i);
}

t_bool	ft_join_and_free(char **line, char *buff_left)
{
	char	*str;
	int		i;

	if (!(str = (char *)malloc(sizeof(char) *
	(ft_strlen(*line) + ft_strlen(buff_left) + 1))))
		return (FALSE);
	i = 0;
	while ((*line)[i])
	{
		str[i] = (*line)[i];
		i++;
	}
	while (*buff_left)
	{
		str[i++] = *buff_left++;
		*(buff_left - 1) = 0;
	}
	str[i] = 0;
	free(*line);
	*line = str;
	return (TRUE);
}

t_bool	ft_new_line(char **line, char *buff_left, size_t i)
{
	buff_left[i++] = 0;
	if (!ft_join_and_free(line, buff_left))
		return (FALSE);
	while (buff_left[i])
	{
		*buff_left = buff_left[i];
		buff_left++;
	}
	*buff_left = 0;
	return (TRUE);
}

int		ft_process(char **line, char *buff_left, ssize_t size, t_bool is_read)
{
	size_t i;

	i = 0;
	while (buff_left[i] && buff_left[i] != '\n')
		i++;
	if (!size && is_read && i == 0 && !ft_strlen(*line))
		return (END_OF_FILE);
	if ((size == BUFFER_SIZE || !is_read) && buff_left[i] != '\n')
		return (ft_join_and_free(line, buff_left) ? CONTINUE_READING : FAILED);
	if ((size != BUFFER_SIZE && is_read) && buff_left[i] != '\n')
		return (ft_join_and_free(line, buff_left) ? END_OF_FILE : FAILED);
	if (buff_left[i] == '\n')
		return (ft_new_line(line, buff_left, i) ? SUCCESS : FAILED);
	return (END_OF_FILE);
}
