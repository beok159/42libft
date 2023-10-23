/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:48:04 by uphokaew          #+#    #+#             */
/*   Updated: 2023/10/17 11:14:32 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i) != '\0')
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*new;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (*(s1 + start) != '\0' && ft_charset(*(s1 + start), set))
		start++;
	while (end > start && ft_charset(*(s1 + (end - 1)), set))
		end--;
	new = (char *)malloc((sizeof(char) * (end - start)) + 1);
	if (new == NULL)
		return (NULL);
	while (start < end)
	{
		*(new + i) = *(s1 + start);
		start++;
		i++;
	}
	*(new + i) = '\0';
	return (new);
}
