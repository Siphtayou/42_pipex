/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:27:20 by agilles           #+#    #+#             */
/*   Updated: 2023/10/18 15:25:51 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;

	s = (unsigned const char *)src;
	d = (unsigned char *)dest;
	if (s == d || n == 0)
		return (dest);
	if (d <= s)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else
	{
		s += n;
		d += n;
		while (n-- > 0)
			*--d = *--s;
	}
	return (dest);
}
