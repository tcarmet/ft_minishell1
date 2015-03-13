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
	else if (ft_strequ("setenv", str[0]))
		ft_sh_setenv(str, all);
	else if (ft_strequ("unsetenv", str[0]))
		ft_sh_unsetenv(str, all);
	else if (ft_strequ("exit", str[0]))
		ft_sh_exit(str);
	// else if (ft_strequ("cd", str))
	// 	ft_sh_cd();
}

void	ft_sh_exit(char **str)
{
	int		i;
	int		num;

	i = 0;
	if (!str[1])
	{
		ft_putendl_fd("exit", 2);
		exit(0);
	}
	else if (str[1])
	{
		while (str[1][i] && ft_isdigit(str[1][i]))
		{
			if (str[1][i + 1] == '\0')
			{
				num = ft_atoi(str[1]);
				ft_putendl_fd("exit", 2);
				exit(num);
			}
			i++;
		}
		ft_putendl_fd("exit: Expression Syntax.", 2);
	}
}