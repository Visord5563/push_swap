/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macair <macair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:51:25 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/23 01:05:37 by macair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void f(){
	system("leaks push_swap");
	}
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

int get_index(t_stack *tmp, int content)
{
	int	i = 0;

	while (tmp)
	{
		if (tmp->content < content)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void index_node(t_stack *a)
{
	t_stack *tmp = a;
	while(tmp)
	{
		tmp->index = get_index(a, tmp->content);
		// printf("---%d\n", tmp->index);
		tmp = tmp->next;
	}
}

int chekp(t_stack *b, int index)
{
	int	p;
	t_stack *tmp;

	tmp = b;
	p = 0;
	while (p < ft_lstsize(b)/2)
	{
		if (tmp->index == index)
			return (1);
		tmp = tmp->next;
		p++;
	}
	return (0);
}

void	stacka(char **av, t_stack **a)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (stack_chek(*a, ft_atoi(av[i])) == 1)
		{
			free_stack(*a);
			ft_error();
		}
		ft_lstadd_back(a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	index_node(*a);
}

void	chek_size(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	if (ft_lstsize(*a) == 3)
		sort_3(a);
	if (ft_lstsize(*a) == 4)
		sort_4(a, b);
	if (ft_lstsize(*a) == 5)                          
		sort_5(a, b);
	if (ft_lstsize(*a) > 5)
		sortall(a, b);
	free_stack(*a);
	free_stack(*b);
	
}

void leaks_bye(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

char **_return_arg(char **av)
{
	int	i;
	char	*agv;
	
	i = 1;
	agv = ft_strdup("");

	while(av[i])
	{
		agv = ft_strjoin(agv, av[i]);
		agv = ft_strjoin(agv, " ");
		i++;
	}
	return (ft_split(agv, ' '));

}

int	main(int ac, char **av)
{

	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);

	av = _return_arg(av);
	stacka(av, &a);
	if (cheksort(a) == 0)
		exit(0);
	chek_size(&a, &b);
	leaks_bye(av);
	return (0);
}
