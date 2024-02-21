/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:28:43 by agilles           #+#    #+#             */
/*   Updated: 2023/10/18 15:57:33 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*src1;
	unsigned const char	*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		if (*src1 != *src2)
		{
			if (*src1 < *src2)
				return (*src1 - *src2);
			else if (*src1 > *src2)
				return (*src1 - *src2);
		}
		src1++;
		src2++;
	}
	return (0);
}
