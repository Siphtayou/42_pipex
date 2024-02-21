/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:51:32 by agilles           #+#    #+#             */
/*   Updated: 2023/10/20 17:26:39 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char *p, char *src1, char *src2, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (len != 0)
	{
		if (src1[j] != '\0')
		{
			p[j] = src1[j];
			j++;
		}
		else
		{
			p[j + i] = src2[i];
			i++;
		}
		len--;
	}
	p[j + i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	char	*src1;
	char	*src2;
	int		len;

	src1 = (char *)s1;
	src2 = (char *)s2;
	len = (ft_strlen(s1) + ft_strlen(s2));
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p = ft_join(p, src1, src2, len);
	return (p);
}
