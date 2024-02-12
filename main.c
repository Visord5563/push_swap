/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:51:25 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/12 03:51:09 by saharchi         ###   ########.fr       */
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

int main(int ac, char **av)
{
    char *agv;
    int i = 1;
    
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
        ft_atoi(av[i]);
        i++;
    }
    return (0);
}