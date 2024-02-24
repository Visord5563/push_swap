/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:45:44 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/24 00:07:31 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_r(char **s, int j)
{
	char	*s1;

	s1 = ft_substr(*s, j, ft_strlen(*s) - j);
	free(*s);
	*s = NULL;
	return (s1);
}

char	*get_newline(char **s, int j)
{
	char	*line;

	line = ft_substr(*s, 0, j);
	*s = get_r(s, j);
	return (line);
}

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*buff;
	int			i;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!string)
		string = ft_strdup("");
	i = read(fd, buff, BUFFER_SIZE);
	while (i >= 0)
	{
		buff[i] = '\0';
		string = ft_strjoin(string, buff);
		if (!string || string[0] == '\0')
			break ;
		if (ft_strchr(string) != -1)
			return (free(buff), get_newline(&string, ft_strchr(string)));
		if (i == 0)
			return (free(buff), get_r(&string, 0));
		i = read(fd, buff, BUFFER_SIZE);
	}
	return (free(buff), free(string), string = NULL, NULL);
}
