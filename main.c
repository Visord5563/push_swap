/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:51:25 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/12 23:21:31 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_chek(char *av)
{
    int i = 0;
    
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
        if ((av[i] == '+' || av[i] == '-') && ((av[i + 1] == '\0' || av[i + 1] == ' ') || (av[i - 1] >= '0' && av[i + 1] <= '9')))
            return (0);
        if (av[i] != ' ' && (av[i] < '0' || av[i + 1] > '9') && !(av[i] == '+' || av[i] == '-'))
            return (0);
        i++;
    }
    return (1);
}

stack_a	*ft_lstlast(stack_a *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(stack_a **lst, stack_a *new)
{
	stack_a	*node;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	node = *lst;
	node = ft_lstlast(*lst);
	node->next = new;
}

stack_a	*ft_lstnew(int content)
{
	stack_a	*list;

	list = malloc(sizeof(stack_a));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

int stack_chek(stack_a *cont, int at_oi)
{

	stack_a	*newlst;

	newlst = cont;
	while (newlst != NULL)
	{
        if (newlst->content == at_oi)
            return (1);
		newlst = newlst->next;
	}
	return (0);  
}

void	stack_clear(stack_a **lst)
{
	stack_a	*node;

	if (!lst)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		free(*lst);
		*lst = node;
	}
}



int main(int ac, char **av)
{
    char *agv;
    int i = 1;
    stack_a *cont;
    
    cont = NULL;
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
        if (stack_chek(cont, ft_atoi(av[i])) == 1)
        {
            stack_clear(&cont);
            return (write(2, "Error", 5));
        }
        ft_lstadd_back(&cont, ft_lstnew(ft_atoi(av[i])));
        i++;
    }
    return (0);
}