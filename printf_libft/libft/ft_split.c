/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:31:30 by agilles           #+#    #+#             */
/*   Updated: 2024/02/06 15:58:04 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == c && i == 0)
		{
			while (s[i + 1] == c)
				i++;
		}
		else if (s[i] == c || s[i + 1] == '\0')
		{
			count++;
			while (s[i + 1] == c && c != '\0')
				i++;
		}
	}
	return (count);
}

static int	word_pos(char const *s, char c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

static int	word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ermalloc(char **split, int index)
{
	while (index >= 0)
		free(split[index--]);
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		index;
	int		j;

	index = 0;
	j = 0;
	i = 0;
	split = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!split || !s)
		return (0);
	while (index < count_word(s, c))
	{
		i = word_pos(s, c, i);
		split[index] = malloc(sizeof(char) * (word_len(s, c, i) + 1));
		if (!split[index])
			return (ermalloc(split, index));
		while (s[i] != '\0' && s[i] != c)
			split[index][j++] = s[i++];
		split[index++][j] = '\0';
		j = 0;
	}
	split[index] = 0;
	return (split);
}
