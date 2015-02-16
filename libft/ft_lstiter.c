/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:09:37 by tcarmet           #+#    #+#             */
/*   Updated: 2014/12/29 17:09:44 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void			ft_lstiter(t_list *el, void (*f)(t_list *elem))
{
	t_list			*next;

	while (el)
	{
		next = el->next;
		f(el);
		el = next;
	}
}
