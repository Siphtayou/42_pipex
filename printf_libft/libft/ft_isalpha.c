/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:41:58 by agilles           #+#    #+#             */
/*   Updated: 2023/10/16 18:05:26 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int n)
{
	if ((n >= 65 && n <= 90) || (n >= 97 && n <= 122))
		return (1);
	return (0);
}

/*int	ft_isdigit(int n)
{
	if ((n >= 48 && n <= 57))
		return (1);
	return (0);
}

int	ft_isalnum(int n)
{
	if ((n >= 48 && n <= 57) || (n >= 65 && n <= 90) || (n >= 97 && n <= 122))
		return (1);
	return (0);
}

int	ft_isascii(int n)
{
	if (n >= 0 && n <= 127)
		return (1);
	return (0);
}

int	ft_isprint(int n)
{
	if (n >= 32 && n <= 126)
		return (1);
	return (0);
}

int	main(int argc, char** argv)
{
	if (argc > 0)
	{
		if (ft_isprint(argv[1][0]) == 1)
			printf("1");
		else
			printf("0");
	}
	return(0);
}*/
