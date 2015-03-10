/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 18:11:55 by tcoppin           #+#    #+#             */
/*   Updated: 2015/03/09 18:11:56 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*ft_strlower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		else
			str[i] = str[i];
		i++;
	}
	return (str);
}

void	ft_sh_error(int i, char *str)
{
	if (i == SYSCALL)
	{
		ft_putstr_fd("ft_minishell1 : command not found: ", 2);
		ft_putendl_fd(str, 2);
	}
}