/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:59:51 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/11 20:12:10 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char			*new;

	if (s1 && s2)
	{
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
		if (new)
		{
			new = ft_strcat(new, s1);
			new = ft_strcat(new, s2);
			new = ft_strcat(new, s3);
			return (new);
		}
	}
	return (NULL);
}
