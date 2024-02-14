/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:21:51 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/14 00:56:01 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_countw(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**ft_free(char **str, int index)
{
	int	i;

	i = 0;
	while (index - i >= 0)
	{
		free(str[index - i]);
		i++;
	}
	free(str);
	return (NULL);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	size_t			i;
	size_t			j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = ft_strlen(s) - start;
	if (len < i)
		i = len;
	s1 = malloc(sizeof(char) * (i + 1));
	if (!s1)
		return (NULL);
	j = 0;
	while (j < i)
	{
		s1[j] = s[j + start];
		j++;
	}
	s1[j] = '\0';
	return (s1);
}

char	**ft_minisplit(char **str, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = -1;
	while (++k < ft_countw(s, c))
	{
		i = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j + i] != c && s[j + i])
			i++;
		str[k] = ft_substr(s, j, i);
		if (!str[k])
			return (ft_free(str, k));
		j += i;
	}
	str[k] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	**p;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_countw(s, c) + 1));
	if (!str)
		return (NULL);
	p = ft_minisplit(str, s, c);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	nstr = (char *)malloc(sizeof(char) * len);
	if (!nstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		nstr[i] = s1[i];
		i++;
	}
	nstr[i++] = ' ';
	j = 0;
	while (s2[j] != '\0')
		nstr[i++] = s2[j++];
	nstr[i++] = '\0';
	return (nstr);
}

int	ft_atoi(const char *str)
{
	int					i;
	long long			r;
	int					s;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		return (write(2, "Error", 5));
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
		if (r * s > 21474836407 || r * s < -21474836408)
			return (write(2, "Error", 5));
	}
	return (r * s);
}
