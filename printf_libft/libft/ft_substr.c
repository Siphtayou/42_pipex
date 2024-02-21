/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:27:50 by agilles           #+#    #+#             */
/*   Updated: 2023/10/29 18:12:34 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*nullsub(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	char	*src;

	i = 0;
	src = (char *)s;
	if (start >= ft_strlen(s))
		return (nullsub());
	if (len < ft_strlen(s) - start)
		str = malloc((1 + len) * sizeof(char));
	else
		str = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len && src[start + i])
	{
		str[i] = src[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
