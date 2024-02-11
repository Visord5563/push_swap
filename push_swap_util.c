/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:21:51 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/11 05:08:05 by saharchi         ###   ########.fr       */
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

static char	**ft_minisplit(char **str, const char *s, char c)
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

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		else if (!s2)
			return (ft_strdup(s1));
	}
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	nstr = (char *)malloc(sizeof(char) * len);
	if (!nstr)
		return (NULL);
	// ft_strlcpy(nstr, s1, ft_strlen(s1) + 1);
	// ft_strlcat(nstr, s2, len);
	return (nstr);
}