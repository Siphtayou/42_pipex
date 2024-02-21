/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:39:33 by agilles           #+#    #+#             */
/*   Updated: 2023/11/07 16:24:58 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countdigit(int nb, int len)
{
	if (nb == -2147483648)
		return (len + 11);
	else if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	len++;
	return (len);
}

int	ft_put_di(int nb, int len)
{
	len = ft_countdigit(nb, len);
	ft_putnbr_fd(nb, 1);
	return (len);
}
