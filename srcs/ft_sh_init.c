/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 16:49:09 by tcoppin           #+#    #+#             */
/*   Updated: 2015/03/13 21:01:59 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_sh_init(t_all *all)
{
	all->env = NULL;
	all->path = NULL;
	all->array = NULL;
	all->home = NULL;
	all->pid = 0;
}

int		ft_sh_check_env(char **env, t_all *all)
{
	char	**str;
	char	*tmp;

	tmp = NULL;
	if (env[0])
		return (1);
	str = (char **)malloc(sizeof(char *) * 3);
	str[0] = ft_strdup("setenv");
	str[1] = ft_strdup("PWD");
	str[2] = getcwd(tmp, 1024);
	all->home = ft_strdup(str[2]);
	ft_sh_setenv(str, all);
	free_tb(&str);
	str = (char **)malloc(sizeof(char *) * 3);
	str[0] = ft_strdup("setenv");
	str[1] = ft_strdup("SHLVL");
	str[2] = ft_strdup("1");
	ft_sh_setenv(str, all);
	free_tb(&str);
	return (0);
}
