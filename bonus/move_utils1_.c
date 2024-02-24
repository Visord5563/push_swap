/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils1_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:39:45 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/24 12:26:44 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*curnt;

	if (!*a || !(*a)->next)
		return ;
	curnt = *a;
	tmp = ft_lstlast(*a);
	while (curnt->next->next)
		curnt = curnt->next;
	curnt->next = NULL;
	ft_lstadd_front(a, tmp);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*curnt;

	if (!*b || !(*b)->next)
		return ;
	curnt = *b;
	tmp = ft_lstlast(*b);
	while (curnt->next->next)
		curnt = curnt->next;
	curnt->next = NULL;
	ft_lstadd_front(b, tmp);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, tmp);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, tmp);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
