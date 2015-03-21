/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:07:39 by tcarmet           #+#    #+#             */
/*   Updated: 2014/12/29 17:08:05 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*el;

	if (alst)
	{
		el = *alst;
		del(el->content, el->content_size);
		ft_memdel((void **)alst);
	}
}
