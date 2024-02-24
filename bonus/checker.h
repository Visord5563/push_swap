/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:16:53 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/24 13:14:02 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_error(void);
void	swap(int *a, int *b);
int		stack_check(t_stack *a, int at_oi);
int		ft_lstsize(t_stack *lst);
int		checksort(t_stack *a);
void	free_stack(t_stack *stack);
void	leaks_bye(char **av);
char	**_return_arg(char **av);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strchr(char *s);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_check(char *av);

#endif