/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:08:24 by uphokaew          #+#    #+#             */
/*   Updated: 2023/08/26 13:08:24 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	dest = (char *)malloc((sizeof(char) * i) + 1);
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (dest != 0 && *(s1 + i) != '\0')
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
