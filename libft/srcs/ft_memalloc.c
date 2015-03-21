/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 00:46:43 by tcarmet           #+#    #+#             */
/*   Updated: 2014/12/01 20:02:19 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if (!size)
		return (NULL);
	str = (void*)malloc(size);
	if (!str)
		return (NULL);
	ft_bzero((void*)str, size);
	return ((void*)str);
}
