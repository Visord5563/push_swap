/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsnorm1_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:40:09 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/23 23:40:10 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	leaks_bye(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	i = 0;
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while ((d1[i] == d2[i]) && (d1[i] != '\0' && d2[i] != '\0'))
		i++;
	return (d1[i] - d2[i]);
}

char	**_return_arg(char **av)
{
	int		i;
	char	*agv;

	i = 1;
	agv = ft_strdup("");
	while (av[i])
	{
		agv = ft_strjoin(agv, av[i]);
		agv = ft_strjoin(agv, " ");
		i++;
	}
	return (ft_split(agv, ' '));
}
