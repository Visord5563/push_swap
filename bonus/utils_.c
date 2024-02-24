/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:39:55 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/24 12:14:59 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * i + 1);
	if (!s)
		return (0);
	j = 0;
	while (j < i)
	{
		s[j] = s1[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(""));
	len = ft_strlen(s1) + ft_strlen(s2);
	nstr = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	while (s1[i])
	{
		nstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		nstr[i] = s2[j];
		i++;
		j++;
	}
	nstr[i] = '\0';
	free((char *)s1);
	return (nstr);
}

int	ft_atoi(const char *str)
{
	long long			r;
	int					s;

	s = 1;
	r = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	if (*str == '+' || *str == '-')
		ft_error();
	while (*str >= '0' && *str <= '9')
	{
		if (r * 10 > 2147483640 || (r * 10 == 2147483640
				&& ((*str > '7' && s == 1) || (*str > '8' && s == -1))))
			ft_error();
		r = r * 10 + (*str - 48);
		str++;
	}
	return (r * s);
}
