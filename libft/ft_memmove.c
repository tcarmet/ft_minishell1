/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:13:01 by tcarmet           #+#    #+#             */
/*   Updated: 2014/11/27 15:10:33 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*copy;
	char	*p1;
	size_t	i;

	copy = ft_strnew(len);
	p1 = (char *)dst;
	i = 0;
	while (i < len)
	{
		copy[i] = ((char *)src)[i];
		i++;
	}
	while (len > 0)
	{
		len--;
		p1[len] = copy[len];
	}
	return (dst);
}
