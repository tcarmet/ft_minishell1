/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:23:44 by tcarmet           #+#    #+#             */
/*   Updated: 2014/12/29 17:23:37 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;

	i = ft_strlen(dst);
	if (size <= i)
		return (size + ft_strlen(src));
	dst = ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	return (i + ft_strlen(src));
}
