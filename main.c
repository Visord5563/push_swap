/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:51:25 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/14 06:55:55 by saharchi         ###   ########.fr       */
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

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	node = *lst;
	node = ft_lstlast(*lst);
	node->next = new;
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
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

void	stack_clear(t_stack **lst)
{
	t_stack	*node;

	while (*lst)
	{
		node = (*lst)->next;
		free(*lst);
		*lst = node;
	}
}

void	sa(t_stack *list)
{
	int	tmp;

	tmp = list->content;
	list->content = list->next->content;
	list->next->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *list)
{
	int	tmp;

	tmp = list->content;
	list->content = list->next->content;
	list->next->content = tmp;
	write(1, "sb\n", 3);
}

void ra(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*curnt;

	tmp = *list;
	curnt = ft_lstlast(*list);
	curnt->next = tmp;
	(*list) = tmp->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void rb(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*curnt;

	tmp = *list;
	curnt = ft_lstlast(*list);
	curnt->next = tmp;
	(*list) = tmp->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

int	main(int ac, char **av)
{
	char		*agv;
	int			i;
	t_stack		*a;

	a = NULL;
	i = 1;
	if (ac == 1)
		return (1);
	while (av[i])
	{
		if (ft_chek(av[i]) == 0)
			return (write(2, "Error", 5));
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
			return (write(2, "Error", 5));
		}
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	ra(&a);
	while (a)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	return (0);
}
