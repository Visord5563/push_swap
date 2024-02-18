/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:51:25 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/18 16:59:53 by saharchi         ###   ########.fr       */
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
	t_stack *tmp = a;
	t_stack *min = a;
	int j = 1;
	while (tmp)
	{
		t_stack *pmt = a;
		while (pmt->next)
		{
			if (tmp->content >= pmt->content && pmt->index == -1)
			{
				j++;
				min = pmt;
			}
			pmt = pmt->next;
		}
		min->index = j;
		printf("min->%d\n", min->content);
		tmp = tmp->next;
	}
	if (i == 2 && cheksort(a) == 1)
		sa(a);
	if (i == 3 && cheksort(a) == 1)
		sort_3(&a);
	// while (tmp)
	// {
	// 	if ()
	// 	tmp = tmp->next;
	// }
	while(a)
	{
		printf("%d index%d\n",a->content, a->index);
		a = a->next;
	}
	stack_clear(&a);
	return (0);
}
