/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:46:00 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/24 13:55:16 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '\0')
		return (0);
	while (av[i] && av[i] == ' ')
		i++;
	if (av[i] == '\0')
		return (0);
	i = 0;
	while (av[i])
	{
		if ((av[i] == '+' || av[i] == '-')
			&& ((av[i + 1] == '\0' || av[i + 1] == ' ')
				|| (av[i - 1] >= '0' && av[i + 1] <= '9')))
			return (0);
		if (av[i] != ' ' && (av[i] < '0' || av[i] > '9')
			&& !(av[i] == '+' || av[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

void	stacka(char **av, t_stack **a)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (stack_check(*a, ft_atoi(av[i])) == 1)
		{
			free_stack(*a);
			ft_error();
		}
		ft_lstadd_back(a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}

void	check(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(*a, *b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b);
	else
		ft_error();
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char		*line;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	av = _return_arg(av);
	stacka(av, &a);
	leaks_bye(av);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		check(line, &a, &b);
		free(line);
	}
	if (checksort(a) == 0 && ft_lstsize(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	return (0);
}
