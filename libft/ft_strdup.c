/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:08:54 by tcarmet           #+#    #+#             */
/*   Updated: 2014/11/25 14:50:44 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char const *s1)
{
	char	*str;
	int		i;

	if (s1)
	{
		str = ft_strnew(ft_strlen(s1));
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