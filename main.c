/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:51:25 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/20 20:36:34 by saharchi         ###   ########.fr       */
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
				|| (av[i - 1] >= '0' && av[i + 1] <= '9')))
			return (0);
		if (av[i] != ' ' && (av[i] < '0' || av[i + 1] > '9')
			&& !(av[i] == '+' || av[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	stack_chek(t_stack *a, int at_oi)
{
	t_stack	*newlst;

	newlst = a;
	while (newlst != NULL)
	{
		if (newlst->content == at_oi)
			return (1);
		newlst = newlst->next;
	}
	return (0);
}

void	sort_3(t_stack **a)
{
		if ((*a)->content < (*a)->next->content )
		{
			if ((*a)->content < (*a)->next->next->content)
			{
				sa(*a);
				ra(a);
			}
			else
				rra(a);
		}
		else if ((*a)->content > (*a)->next->content)
		{
			if ((*a)->next->content > (*a)->next->next->content)
			{
				sa(*a);
				rra(a);
			}
			else if ((*a)->content > (*a)->next->next->content)
				ra(a);
			else
				sa(*a);
		}
}

void	ft_error()
{
	write(2, "Error", 5);
	exit(0);
}

int cheksort(t_stack *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}

int	ft_lstsize(t_stack *lst)
{
	t_stack	*newlst;
	int		i;

	if (!lst)
		return (0);
	i = 0;
	newlst = lst;
	while (newlst != NULL)
	{
		i++;
		newlst = newlst->next;
	}
	return (i);
}

int get_index(t_stack *tmp, int content)
{
	int	i = 0;

	while (tmp)
	{
		if (tmp->content < content)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void index_node(t_stack *a)
{
	t_stack *tmp = a;
	while(tmp)
	{
		tmp->index = get_index(a, tmp->content);	
		tmp = tmp->next;
	}
}

void sort_4(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index == 1)
			break;
		else if (ft_lstlast(*a)->index == 1)
			rra(a);
		else
			ra(a);
		tmp = *a;
	}
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void sort_5(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index == 2)
			break;
		else if (ft_lstlast(*a)->index == 2)
			rra(a);
		else
			ra(a);
		tmp = *a;
	}
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
	sa(*a);
}

void	sortall(t_stack **a, t_stack **b)
{
	int p1;
	int p2;

	p2 = 0;
	while (ft_lstsize(*a) > 3)
	{
		p1 = ft_lstsize(*a)/6 + p2;
		p2 = ft_lstsize(*a)/3 + p2;
		while (a && p2 > ft_lstsize(*b))
		{
			
			if ((*a)->index < p2)
			{
				pb(a, b);
				if ((*b)->index < p1 && ft_lstsize(*b) > 1)
					rb(b);
			}
			else
				ra(a);
			// (*b) = (*b);
			(*a) = (*a);
		}
	}
	if (cheksort(*a) == 1)
		sort_3(a);
}

int	main(int ac, char **av)
{
	char		*agv;
	int			i;
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	i = 1;
	if (ac == 1)
		return (1);
	while (av[i])
	{
		if (ft_chek(av[i]) == 0)
			ft_error();
		agv = ft_strjoin(agv, av[i]);
		i++;
	}
	i = 0;
	av = NULL;
	av = ft_split(agv, ' ');
	while (av[i])
	{
		if (stack_chek(a, ft_atoi(av[i])) == 1)
		{
			stack_clear(&a);
			ft_error();
		}
		free(av[i]);
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	free(av);
	index_node(a);
	if (cheksort(a) == 0)
		exit(1);
	if (i == 2)
		sa(a);
	if (i == 3)
		sort_3(&a);
	if (i == 4)
		sort_4(&a, &b);
	if (i == 5)                          
		sort_5(&a, &b);
	if (i > 5)
		sortall(&a, &b);
	// while (a)
	// {
	// 	printf("a-----|%d\n", a->content);
	// 	a = a->next;
	// // printf("hhh\n");
	// }
	// while (b)
	// {
	// 	printf("b----|%d\n", b->content);
	// 	b = b->next;
	// // printf("hhh\n");
	// }
	// stack_clear(&a);
	return (0);
}
