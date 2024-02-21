/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:55:18 by agilles           #+#    #+#             */
/*   Updated: 2023/11/09 16:29:30 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counthex(unsigned long long n, int len)
{
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	len++;
	return (len);
}

static void	ft_putp(unsigned long long n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_putp(n / 16);
	n = n % 16;
	ft_putchar_fd(hex[n], 1);
}

int	ft_put_p(unsigned long n, int len)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (len + 5);
	}
	else
	{
		write(1, "0x", 2);
		len += 2;
		len = ft_counthex(n, len);
		ft_putp(n);
	}
	return (len);
}
