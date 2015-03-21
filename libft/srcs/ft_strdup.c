/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:32:08 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/10 17:59:04 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(char const *s1)
{
	char	*str;
	int		i;

	if (s1)
	{
		str = ft_strnew(ft_strlen(s1) + 1);
		if (str)
		{
			i = 0;
			while (s1[i])
			{
				str[i] = s1[i];
				i++;
			}
			return (str);
		}
	}
	return (NULL);
}
