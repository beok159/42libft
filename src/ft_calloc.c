/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:08:34 by uphokaew          #+#    #+#             */
/*   Updated: 2023/08/26 13:08:34 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	if (count > SIZE_MAX)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	i = count * size;
	while (i > 0)
	{
		*(char *)(p + (i - 1)) = '\0';
		i--;
	}
	return (p);
}
