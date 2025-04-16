/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:23:57 by rispay-s          #+#    #+#             */
/*   Updated: 2024/11/09 12:31:03 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countsstring(char const *s, char c)
{
	size_t	i;
	size_t	countword;

	i = 0;
	countword = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			countword++;
		i++;
	}
	return (countword);
}

static void	ft_makewords(char *newword, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		newword[i] = s[i];
		i++;
	}
	newword[i] = '\0';
}

static void	*ft_allfree(char **newstring, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(newstring[i]);
		i++;
	}
	free(newstring);
	return (NULL);
}

static char	**ft_fillstring(char **newstring, char const *s, char c)
{
	size_t	i;
	size_t	index;
	size_t	count;

	i = 0;
	index = 0;
	while (s[index])
	{
		count = 0;
		while (s[index + count] != '\0' && s[index + count] != c)
			count++;
		if (count > 0)
		{
			newstring[i] = malloc(sizeof(char) * (count + 1));
			if (!newstring[i])
				return (ft_allfree(newstring, i));
			ft_makewords(newstring[i], s + index, c);
			i++;
			index = index + count;
		}
		else
			index++;
	}
	newstring[i] = 0;
	return (newstring);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**newstring;

	if (!s)
		return (NULL);
	words = ft_countsstring(s, c);
	newstring = (char **)ft_calloc((words + 1), (sizeof(char *)));
	if (!newstring)
		return (NULL);
	newstring = ft_fillstring(newstring, s, c);
	return (newstring);
}
