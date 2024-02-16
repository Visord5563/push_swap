/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:56:43 by saharchi          #+#    #+#             */
/*   Updated: 2024/02/16 02:18:58 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countw(char const *s, char c)
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
	free((char *)s);
	return (p);
}
