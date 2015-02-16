/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:08:26 by tcarmet           #+#    #+#             */
/*   Updated: 2014/12/29 17:08:27 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list			*el;
	t_list			*next;
	t_list			**ptr;

	if (alst)
	{
		el = *alst;
		while (el)
		{
			next = el->next;
			ptr = &el;
			ft_lstdelone(ptr, del);
			el = next;
		}
		*alst = NULL;
	}
}
