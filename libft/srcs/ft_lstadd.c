/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:09:04 by tcarmet           #+#    #+#             */
/*   Updated: 2014/12/29 17:09:12 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void			ft_lstadd(t_list **alst, t_list *new)
{
	t_list			*el;

	if (alst)
	{
		el = *alst;
		new->next = el;
		*alst = new;
	}
}
