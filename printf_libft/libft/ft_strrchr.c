/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:50:03 by agilles           #+#    #+#             */
/*   Updated: 2023/10/19 17:11:07 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)s;
	while (p[i])
		i++;
	if (p[i] == '\0' && (char)c == '\0')
		return (p + i);
	i--;
	while (p[i] && i != -1)
	{
		if (p[i] == (char)c)
			return (p + i);
		i--;
	}
	return (NULL);
}
