/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:49:48 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/24 00:35:29 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	swap(&(*a)->content, &(*a)->next->content);
	swap(&(*a)->index, &(*a)->next->index);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	swap(&(*b)->content, &(*b)->next->content);
	swap(&(*b)->index, &(*b)->next->index);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(&a);
	sb(&b);
	write(1, "ss\n", 3);
}

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*curnt;

	if (ft_lstsize(*a) == 0)
		return ;
	tmp = *a;
	curnt = ft_lstlast(*a);
	curnt->next = tmp;
	(*a) = tmp->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*curnt;

	if (ft_lstsize(*b) == 0)
		return ;
	tmp = *b;
	curnt = ft_lstlast(*b);
	curnt->next = tmp;
	(*b) = tmp->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}
