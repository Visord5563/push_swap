/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:21:15 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/22 22:44:42 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
		if ((*a)->content < (*a)->next->content )
		{
			if ((*a)->content < (*a)->next->next->content)
			{
				sa(a);
				ra(a);
			}
			else
				rra(a);
		}
		else if ((*a)->content > (*a)->next->content)
		{
			if ((*a)->next->content > (*a)->next->next->content)
			{
				sa(a);
				rra(a);
			}
			else if ((*a)->content > (*a)->next->next->content)
				ra(a);
			else
				sa(a);
		}
}

void sort_4(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index == 0)
			break;
		else if (ft_lstlast(*a)->index == 0)
			rra(a);
		else
			ra(a);
		tmp = *a;
	}
	pb(a, b);
	if (cheksort(*a) == 1)
		sort_3(a);
	pa(a, b);
}

void sort_5(t_stack **a, t_stack **b)
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
	sort_4(a, b);
	pa(a, b);
	sa(a);
}

void finalsort(t_stack **a, t_stack **b)
{
    int	biggindex;
    
	biggindex = ft_lstlast(*a)->index;
	while (ft_lstsize(*b) != 0)
	{
		if ((*b)->index == ((*a)->index - 1))
			pa(a, b);
		else if (ft_lstlast(*b)->index == ((*a)->index - 1))
			(rrb(b), pa(a, b));
		else if (ft_lstlast(*a)->index == biggindex || ft_lstlast(*a)->index < (*b)->index)
			(pa(a, b), ra(a));
		else if ( ft_lstlast(*a)->index < ft_lstlast(*b)->index)
			(rrb(b), pa(a, b), ra(a));
		else if (ft_lstlast(*a)->index == ((*a)->index - 1))
			rra(a);
		else if (chekp(*b, ((*a)->index - 1)) == 1)
			rb(b);
		else
			rrb(b);
	}
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
			(*a) = (*a);
		}
	}
	if (cheksort(*a) == 1)
		sort_3(a);
	finalsort(a, b);
}
