/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:52:18 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/23 13:32:39 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*curnt;

	curnt = *a;
	tmp = ft_lstlast(*a);
	while (curnt->next->next)
		curnt = curnt->next;
	curnt->next = NULL;
	ft_lstadd_front(a, tmp);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*curnt;

	curnt = *b;
	tmp = ft_lstlast(*b);
	while (curnt->next->next)
		curnt = curnt->next;
	curnt->next = NULL;
	ft_lstadd_front(b, tmp);
	write(1, "rrb\n", 4);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, tmp);
	write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, tmp);
	write(1, "pa\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
