/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:39:37 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/24 00:28:08 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	swap(&(*a)->content, &(*a)->next->content);
}

void	sb(t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	swap(&(*b)->content, &(*b)->next->content);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(&a);
	sb(&b);
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
}
