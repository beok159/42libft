/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:02:02 by uphokaew          #+#    #+#             */
/*   Updated: 2023/08/26 13:02:02 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr;

	ptr = (const char *)s;
	while (n != 0 && *ptr != (char)c)
	{
		ptr++;
		n--;
	}
	if (n != 0)
		return ((void *)ptr);
	return (NULL);
}
