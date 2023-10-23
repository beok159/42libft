/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:03:13 by uphokaew          #+#    #+#             */
/*   Updated: 2023/08/26 13:03:13 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (*(dst + i) != '\0' && i < dstsize)
		i++;
	while (*(src + j) != '\0' && (i + j + 1) < dstsize)
	{
		*(dst + (i + j)) = *(src + j);
		j++;
	}
	if (i < dstsize)
		*(dst + (i + j)) = '\0';
	while (*(src + len) != '\0')
		len++;
	return (i + len);
}
