/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:44:07 by uphokaew          #+#    #+#             */
/*   Updated: 2023/09/17 22:44:07 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cword(char c, char const *s)
{
	size_t	count;
	size_t	i;
	int		inword;

	count = 0;
	inword = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			inword = 0;
		else if (inword == 0)
		{
			inword = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (n > 0 && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
		n--;
	}
	*(dest + i) = '\0';
	return (dest);
}

static char	**ft_freealloc(char **alloc)
{
	size_t	i;

	i = 0;
	while (*(alloc + i) != NULL)
	{
		free(*(alloc + i));
		i++;
	}
	free(alloc);
	return (NULL);
}

static char	**ft_allocate(char **alloc, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	len;
	size_t	start;

	i = 0;
	start = 0;
	while (i < count)
	{
		len = 0;
		while (*(s + start) == c)
			start++;
		while (*(s + (start + len)) && *(s + (start + len)) != c)
			len++;
		*(alloc + i) = (char *)malloc(len + 1);
		if (*(alloc + i) == NULL)
			return (ft_freealloc(alloc));
		ft_strncpy(*(alloc + i), s + start, len);
		start += len;
		i++;
	}
	*(alloc + i) = NULL;
	return (alloc);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = ft_cword(c, s);
	new = (char **)malloc(sizeof(char *) * (count + 1));
	if (new == NULL)
		return (NULL);
	new = ft_allocate(new, s, c, count);
	return (new);
}
