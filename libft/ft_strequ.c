/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:08:47 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/11 18:08:48 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned int i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] && s2[i])
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (s1[i] != '\0' || s2[i] != '\0')
			return (0);
		return (1);
	}
	return (0);
}
