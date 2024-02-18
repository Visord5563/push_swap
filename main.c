/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:51:25 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/18 19:19:22 by saharchi         ###   ########.fr       */
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
int get_getmin(t_stack *a)
{
	int min  =0;
	while(a && a->next)
	{
		if(a->content < a->next->content && a->content < min && a->index == -1)
			min = a->content;
		a = a->next;
	}
	if(a->content < min)
			min = a->content;
	return min;
}
int index_all_items(t_stack *a)
{
	int o = 0;
	int min = get_getmin(a);
	
	while(a)
	{
		o++;
		if(a->content == min)
			a->index = o;

		a = a->next;	
	}
	return EXIT_SUCCESS;
}


int get_min_position(t_stack *a)
{
	int min = get_getmin(a);
	int pos = 0;
	while(a)
	{
		pos++;
		if(a->content == min)
			return pos;
		
		a = a->next;
	}
	return -1;
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
	// t_stack *min = a;
	// while (tmp)
	// {
	// 	t_stack *pmt = tmp;
	// 	while (pmt)
	// 	{
	// 		if (tmp->content > pmt->content && pmt->index == -1)
	// 		{
	// 			min = pmt;
	// 		}
	// 		printf("pmt->%d tmp->%d min->%d\n", pmt->content, tmp->content, min->content);
	// 		pmt = pmt->next;
	// 	}
	// 	min->index = j;
	// 	printf("\nmin->index %d\n", min->index);
	// 	j++;
	// 	tmp = tmp->next;
	// }
	if (i == 2 && cheksort(a) == 1)
		sa(a);
	if (i == 3 && cheksort(a) == 1)
		sort_3(&a);
	index_all_items(a);
	while(a)
	{
		printf("%d\n",a->index);
		a = a->next;
	}
	// while(a)
	// {
	// 	a = a->next;
	// }
	// stack_clear(&a);
	return (0);
}
