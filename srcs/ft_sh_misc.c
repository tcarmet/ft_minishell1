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
	else if (i == SYSPID)
		ft_putendl_fd("plop", 2);
	else if (i == EXEC_ERROR)
		ft_putendl_fd("EXEC_ERROR", 2);
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

size_t	ft_strlen_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tb(char ***s)
{
	int	i;

	i = 0;
	while ((*s)[i])
	{
		free((*s)[i]);
		(*s)[i] = NULL;
		i++;
	}
	free(*s);
	*s = NULL;
}
