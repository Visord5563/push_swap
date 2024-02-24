/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:51:25 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/24 15:56:31 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chek(char *av)
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
				|| (av[i - 1] >= '0' && av[i - 1] <= '9')))
			return (0);
		if (av[i] != ' ' && (av[i] < '0' || av[i] > '9')
			&& !(av[i] == '+' || av[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	checkp(t_stack *b, int index)
{
	int		p;
	t_stack	*tmp;

	tmp = b;
	p = 0;
	while (p < (ft_lstsize(b) / 2))
	{
		if (tmp->index == index)
			return (1);
		tmp = tmp->next;
		p++;
	}
	return (0);
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
	index_node(*a);
}

void	check_size(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	if (ft_lstsize(*a) == 3)
		sort_3(a);
	if (ft_lstsize(*a) == 4)
		sort_4(a, b);
	if (ft_lstsize(*a) == 5)
		sort_5(a, b);
	if (ft_lstsize(*a) > 5)
		sortall(a, b);
	free_stack(*a);
	free_stack(*b);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	av = _return_arg(av);
	stacka(av, &a);
	if (checksort(a) == 0)
		exit(0);
	check_size(&a, &b);
	leaks_bye(av);
	return (0);
}
