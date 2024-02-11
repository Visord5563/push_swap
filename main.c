/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:51:25 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/11 06:41:01 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_chek(char *av)
{
    int i = 0;
    while (av[i])
    {
        if ((av[i] == '+' || av[i] == '-') && ((av[i + 1] == '\0' || av[i + 1] == ' ') || (av[i - 1] >= '0' && av[i + 1] <= '9')))
            return (0);
        if (av[i] != ' ' && (av[i] < '0' || av[i + 1] > '9') && (av[i] != '+' || av[i] != '-'))
            return (0);
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    char **agv;
    int i = 1;
    
    while (av[i])
    {
        if (ft_chek(av[i]) == 0)
            return (write(2, "Error", 5));
        printf("ok");
        i++;
    }
    return (0);
}