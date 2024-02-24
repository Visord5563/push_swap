/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsnorm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:16:41 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/24 15:52:00 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_index(t_stack *tmp, int content)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (tmp->content < content)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	index_node(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		tmp->index = get_index(a, tmp->content);
		tmp = tmp->next;
	}
}

char	**_return_arg(char **av)
{
	int		i;
	char	*agv;

	i = 1;
	agv = ft_strdup("");
	while (av[i])
	{
		if (!ft_chek(av[i]))
			ft_error();
		agv = ft_strjoin(agv, av[i]);
		agv = ft_strjoin(agv, " ");
		i++;
	}
	return (ft_split(agv, ' '));
}
