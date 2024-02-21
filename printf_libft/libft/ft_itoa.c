/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:14:40 by agilles           #+#    #+#             */
/*   Updated: 2023/10/29 18:12:50 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int	digit;

	digit = !n;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		sign;
	int		digit;

	sign = n < 0;
	digit = digit_count(n) + sign;
	res = malloc(sizeof(char) * (digit + 1));
	if (!res)
		return (0);
	res[digit] = '\0';
	if (sign)
	{
		*res = '-';
		res[--digit] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (digit-- - sign)
	{
		res[digit] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
