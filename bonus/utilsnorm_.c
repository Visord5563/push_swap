/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsnorm_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:40:02 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/24 00:24:29 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}

int	stack_check(t_stack *a, int at_oi)
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

int	checksort(t_stack *a)
{
	if (a == NULL)
		return (0);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}
