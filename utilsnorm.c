/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsnorm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:08:58 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/23 13:28:37 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
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

void	ft_error(void)
{
	write(2, "Error", 5);
	exit(0);
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

int	cheksort(t_stack *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}
