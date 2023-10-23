/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:03:26 by uphokaew          #+#    #+#             */
/*   Updated: 2023/08/26 13:03:26 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*ptr;

	ptr = (char *)s;
	len = 0;
	while (*(s + len) != '\0')
		len++;
	i = len;
	if (c == 0)
		return (ptr + i);
	while (i >= 0)
	{
		if (*(s + i) == (unsigned char)c)
			return (ptr + i);
		i--;
	}
	return (NULL);
}
