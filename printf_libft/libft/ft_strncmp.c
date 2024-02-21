/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:55:14 by agilles           #+#    #+#             */
/*   Updated: 2023/10/19 16:17:15 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	int				i;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	i = 0;
	if (n <= 0)
		return (0);
	while (--n > 0)
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		else if (src1[i] == '\0' || src2[i] == '\0')
			return (0);
		i++;
	}
	return (src1[i] - src2[i]);
}
