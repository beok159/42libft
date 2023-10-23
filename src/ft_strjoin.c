/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:06:48 by uphokaew          #+#    #+#             */
/*   Updated: 2023/08/26 19:06:48 by uphokaew         ###   ########.fr       */
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
	}
	*(allocate + i) = '\0';
	return (allocate);
}

static char	*ft_strcpy_cat(const char *s1, const char *s2, size_t allocate_l)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = ft_allocate(allocate_l, 0, "");
	if (str == NULL)
		return (str);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j) != '\0')
	{
		*(str + i) = *(s2 + j);
		j++;
		i++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if ((s1 == 0 && s2 == 0) || (s1 != 0 && s2 == 0) || (s1 == 0 && s2 != 0))
		return (ft_allocate(0, 1, ""));
	i = 0;
	j = 0;
	while (*(s1 + i) != '\0')
		i++;
	while (*(s2 + j) != '\0')
	{
		i++;
		j++;
	}
	str = ft_strcpy_cat(s1, s2, i);
	return (str);
}
