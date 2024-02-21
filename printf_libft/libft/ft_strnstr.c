/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:07:47 by agilles           #+#    #+#             */
/*   Updated: 2023/10/29 17:42:34 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	char	*b;

	b = (char *)big;
	little_len = ft_strlen(little);
	if (*little == '\0')
		return (b);
	else if (ft_strlen(b) < ft_strlen(little))
		return (0);
	while ((*b + little_len) != '\0'
		&& len != 0 && len >= little_len)
	{
		if (ft_strncmp(b, little, little_len) == 0)
			return (b);
		b++;
		len--;
	}
	return (0);
}

/*char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	else if (ft_strlen(big) < ft_strlen(little))
		return (NULL);
	while ((*(char *)big + little_len) != '\0'
		&& len != 0 && len >= little_len)
	{
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		(char *)big++;
		len--;
	}
	return (NULL);
}*/
