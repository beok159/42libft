/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:52:12 by uphokaew          #+#    #+#             */
/*   Updated: 2023/09/18 10:52:12 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_allocate(size_t size, int mode, const char *str)
{
	char	*allocate;
	size_t	i;

	i = size;
	if (mode != 0)
		i = 0;
	allocate = (char *)malloc((sizeof(char) * i) + 1);
	if (allocate == NULL)
		return (NULL);
	while (mode != 0 && *(str + i) != '\0' && i < size)
	{
		*(allocate + i) = *(str + i);
		i++;
	}
	*(allocate + i) = '\0';
	return (allocate);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	newlen;
	char			*substr;
	size_t			i;

	i = 0;
	newlen = 0;
	while (*(s + i) != '\0')
		i++;
	if (start > i)
		return (ft_allocate(0, 1, ""));
	newlen = i - start;
	if (len > newlen)
		len = newlen;
	substr = ft_allocate(len, 0, "");
	if (substr == NULL)
		return (substr);
	i = 0;
	while (i < len)
	{
		*(substr + i) = *(s + (start + i));
		i++;
	}
	return (substr);
}
