/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:12:32 by agilles           #+#    #+#             */
/*   Updated: 2023/11/09 16:27:21 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printarg(char c, va_list *arg, int len)
{
	if (c == 'c')
		len = ft_printf_putchar((char)va_arg(*arg, int), len);
	else if (c == 's')
		len = ft_put_s(va_arg(*arg, char *), len);
	else if (c == 'p')
		len = ft_put_p(va_arg(*arg, unsigned long), len);
	else if (c == 'd' || c == 'i')
		len = ft_put_di(va_arg(*arg, int), len);
	else if (c == 'u')
		len = ft_put_u(va_arg(*arg, unsigned int), len);
	else if (c == 'x' || c == 'X')
		len = ft_put_x(va_arg(*arg, unsigned int), len, c);
	else if (c == '%')
		len = ft_printf_putchar('%', len);
	return (len);
}

int	ft_printna(const char *src, va_list *arg, int len)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '%')
		{
			len = ft_printarg(src[i + 1], arg, len);
			i += 2;
		}
		else
		{
			ft_putchar_fd(src[i], 1);
			len++;
			i++;
		}
	}
	return (len);
}

int	ft_printf(const char *src, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, src);
	len = ft_printna(src, &arg, len);
	va_end(arg);
	return (len);
}
