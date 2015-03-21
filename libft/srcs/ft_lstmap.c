/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:05:09 by tcarmet           #+#    #+#             */
/*   Updated: 2014/12/29 17:05:25 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*new;
	t_list			*first;

	if (lst && f)
	{
		new = f(lst);
		if (new)
		{
			first = new;
			while (lst->next)
			{
				lst = lst->next;
				new->next = f(lst);
				new = new->next;
				if (!new)
					return (NULL);
			}
			return (first);
		}
	}
	return (NULL);
}
