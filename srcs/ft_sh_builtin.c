/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 17:51:39 by tcarmet           #+#    #+#             */
/*   Updated: 2015/04/05 01:02:50 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
**	ft_is_builtin will check if the argument is a builtin.
*/
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

/*
**	ft_exec_builtin will execute the right builtin.
*/
void	ft_exec_builtin(char **str, t_all *all)
{
	if (ft_strequ("env", str[0]))
		ft_sh_env(str, all);
	else if (ft_strequ("setenv", str[0]))
		ft_sh_setenv(str, all);
	else if (ft_strequ("unsetenv", str[0]))
		ft_sh_unsetenv(str, all);
	else if (ft_strequ("exit", str[0]))
		ft_sh_exit(str);
	else if (ft_strequ("cd", str[0]))
		ft_sh_cd(str, all);
}

/*
**	ft_sh_exit will exit the minishell when the exit builtin is called.
*/
void	ft_sh_exit(char **str)
{
	int		i;
	int		num;

	i = 0;
	if (!str[1])
	{
		ft_putendl_fd("exit", 1);
		exit(0);
	}
	else if (str[1])
	{
		while (!str[2] && str[1][i] && ft_isdigit(str[1][i]))
		{
			if (str[1][i + 1] == '\0')
			{
				num = ft_atoi(str[1]);
				ft_putendl_fd("exit", 1);
				exit(num);
			}
			i++;
		}
		ft_putendl_fd("exit: Expression Syntax.", 2);
	}
}
