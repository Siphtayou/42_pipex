/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:47:13 by agilles           #+#    #+#             */
/*   Updated: 2023/11/08 17:19:50 by agilles          ###   ########.fr       */
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

static void	ft_put_hex(unsigned long long n, char c)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		ft_put_hex(n / 16, c);
	n = n % 16;
	ft_putchar_fd(hex[n], 1);
}

int	ft_put_x(unsigned long long n, int len, char c)
{
	len = ft_counthex(n, len);
	ft_put_hex(n, c);
	return (len);
}
