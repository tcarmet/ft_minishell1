/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 12:55:22 by tcoppin           #+#    #+#             */
/*   Updated: 2015/03/10 12:55:22 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_is_builtin(char *str)
{
	if (ft_strequ("env", str))
		return (1);
	else if (ft_strequ("cd", str))
		return (1);
	else if (ft_strequ("setenv", str))
		return (1);
	else if (ft_strequ("unsetenv", str))
		return (1);
	else if (ft_strequ("exit", str))
		return (1);
	else
		return (0);
}

void	ft_exec_builtin(char **str, t_all *all)
{
	if (ft_strequ("env", str[0]))
		ft_print_env(all);
	// else if (ft_strequ("cd", str))
	// 	return (1);
	// else if (ft_strequ("setenv", str))
	// 	return (1);
	// else if (ft_strequ("unsetenv", str))
	// 	return (1);
	// else if (ft_strequ("exit", str))
	// 	return (1);
}
