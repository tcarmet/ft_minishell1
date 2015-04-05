/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 17:52:29 by tcarmet           #+#    #+#             */
/*   Updated: 2015/04/05 18:09:47 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
**	this function will initialize the struct's variable.
*/
void	ft_sh_init(t_all *all)
{
	all->env = NULL;
	all->path = NULL;
	all->array = NULL;
	all->home = NULL;
	all->pid = 0;
}

/*
**	ft_sh_check_env will verify if there is an environment.
**	if there isn't we will create a mini one.
*/
int		ft_sh_check_env(char **env, t_all *all)
{
	char	**str;
	char	*tmp;

	tmp = NULL;
	if (env[0])
		return (1);
	str = (char **)malloc(sizeof(char *) * 4);
	str[0] = ft_strdup("setenv");
	str[1] = ft_strdup("PWD");
	str[2] = getcwd(tmp, 1024);
	str[3] = NULL;
	all->home = ft_strdup(str[2]);
	ft_sh_setenv(str, all);
	ft_free_tb(&str);
	str = (char **)malloc(sizeof(char *) * 4);
	str[0] = ft_strdup("setenv");
	str[1] = ft_strdup("SHLVL");
	str[2] = ft_strdup("1");
	str[3] = NULL;
	ft_sh_setenv(str, all);
	ft_free_tb(&str);
	return (0);
}

