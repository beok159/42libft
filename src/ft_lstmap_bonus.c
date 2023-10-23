/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:55:57 by uphokaew          #+#    #+#             */
/*   Updated: 2023/10/14 13:12:04 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (temp == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		temp -> content = f(lst->content);
		temp -> next = NULL;
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
