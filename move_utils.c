/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:49:48 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/16 01:50:21 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	tmp;

	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*curnt;

	tmp = *a;
	curnt = ft_lstlast(*a);
	curnt->next = tmp;
	(*a) = tmp->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*curnt;

	tmp = *b;
	curnt = ft_lstlast(*b);
	curnt->next = tmp;
	(*b) = tmp->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}