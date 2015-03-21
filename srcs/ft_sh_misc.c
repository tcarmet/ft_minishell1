/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 17:53:07 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/15 17:53:07 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_sh_error(int i, char *str)
{
	if (i == SYSCALL)
	{
		ft_putstr_fd("ft_minishell1 : command not found: ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (i == SYSPID)
		ft_putendl_fd("ft_minishell1: fork failed: resource unavailable", 2);
	else if (i == ARG_ENV)
		ft_putendl_fd("setenv: Too many arguments.", 2);
	else if (i == UNSET_ARG)
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
	else if (i == ENV_ERROR)
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else if (i == CD_ERROR)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
}

char	*ft_leave_tab(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\t')
			cmd[i] = ' ';
		i++;
	}
	return (cmd);
}
