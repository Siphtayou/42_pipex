/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:41:05 by agilles           #+#    #+#             */
/*   Updated: 2024/01/16 14:49:47 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nb)
{
	long	res;
	int		s;
	int		i;

	res = 0;
	s = 1;
	i = 0;
	while (nb[i] == 32 || nb[i] == 9 || nb[i] == 12
		|| nb[i] == 10 || nb[i] == 11 || nb[i] == 13)
		i++;
	if (nb[i] == '-')
	{
		s = -1;
		i++;
		if (nb[i] < '0' || nb[i] > '9')
			return (0);
	}
	if (nb[i] == '+')
		i++;
	while (nb[i] >= 48 && nb[i] <= 57)
	{
		res = res * 10 + nb[i] - '0';
		i++;
	}
	return (res * s);
}
