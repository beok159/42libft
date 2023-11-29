/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:35:16 by uphokaew          #+#    #+#             */
/*   Updated: 2023/10/16 12:06:42 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	long	nbr;
	size_t	len;

	len = 0;
	nbr = (long)n;
	if (nbr == 0)
		len = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		len += 1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	long	nl;

	nl = (long)n;
	len = ft_nbrlen(n);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (str);
	if (nl < 0)
	{
		*(str + 0) = '-';
		nl = nl * -1;
	}
	if (nl == 0)
		*(str + 0) = '0';
	while (nl > 0 && len > 0)
	{
		*(str + (len - 1)) = (nl % 10) + '0';
		nl /= 10;
		len--;
	}
	return (str);
}
