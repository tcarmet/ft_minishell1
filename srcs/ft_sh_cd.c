/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 17:51:52 by tcarmet           #+#    #+#             */
/*   Updated: 2015/04/05 18:03:13 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
**	This function will modify the pwd.
*/
void	ft_sh_mod_pwd(t_all *all, char *str, char *pwd)
{
	t_env	*env;

	if (!all->env)
	{
		all->env = env_init();
		all->env->var = ft_strdup(str);
	}
	env = all->env;
	while (env->next && !ft_strequ(str, env->var))
		env = env->next;
	if (!ft_strequ(str, env->var))
	{
		env->next = (t_env *)malloc(sizeof(t_env));
		env = env->next;
		env->var = ft_strdup(str);
		env->value = NULL;
		env->next = NULL;
	}
	if (env->value)
		free(env->value);
	env->value = ft_strdup(pwd);
}

/*
**	ft_sh_cd is the main function of the cd builtin. it will choose
**	wich behavement cd will have.
*/
void	ft_sh_cd(char **str, t_all *all)
{
	char	*pwd;
	char	*tmp;

	tmp = NULL;
	pwd = getcwd(tmp, 1024);
	if (str[1] && !str[2])
	{
		if (str[1][0] == '-' && str[1][1])
			ft_putendl_fd("Usage: cd [-][-|<dir>].", 2);
		else if (str[1][0] == '-')
			ft_sh_cd_option(all, pwd);
		else
			ft_sh_chdir(pwd, all, str[1]);
	}
	else if (!str[1])
		ft_sh_chdir(pwd, all, all->home);
	else
		ft_putendl_fd("cd: Too many arguments.", 2);
	if (pwd)
		free(pwd);
}

/*
**	ft_sh_chdir will change the directory 
*/
void	ft_sh_chdir(char *pwd, t_all *all, char *str)
{
	char	*tmp;

	tmp = NULL;
	if (chdir(str) < 0)
		ft_sh_error(CD_ERROR, str);
	else
	{
		ft_sh_mod_pwd(all, "OLDPWD", pwd);
		tmp = NULL;
		pwd = getcwd(tmp, 1024);
		ft_sh_mod_pwd(all, "PWD", pwd);
		if (pwd)
			free(pwd);
	}
}

/*
**	ft_sh_cd_option will look for the OLDPWD value. and will change
**	the directory path.
*/

void	ft_sh_cd_option(t_all *all, char *pwd)
{
	t_env	*env;

	env = all->env;
	while (env && !ft_strequ(env->var, "OLDPWD"))
		env = env->next;
	if (env && ft_strequ(env->var, "OLDPWD"))
		ft_sh_chdir(pwd, all, env->value);
	else
		ft_putendl_fd("No such file or directory.", 2);
}
