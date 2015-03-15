/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:56:18 by tcoppin           #+#    #+#             */
/*   Updated: 2015/03/15 17:47:53 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_env	*env_init(void)
{
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	env->var = NULL;
	env->value = NULL;
	env->next = NULL;
	return (env);
}

t_env	*env_fill(char *var, char *value)
{
	t_env	*env;

	env = env_init();
	env->var = ft_strdup(var);
	env->value = ft_strdup(value);
	return (env);
}

void	ft_sh_push(t_all *all, t_env *env)
{
	t_env	*tmp;

	if (all->env == NULL)
		all->env = env;
	else
	{
		tmp = all->env;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = env;
		tmp = NULL;
	}
}

void	ft_stock_env(char **envp, t_all *all)
{
	t_env	*env;
	int		i;
	char	**env_tab;

	i = 0;
	while (envp[i])
	{
		env = NULL;
		env_tab = ft_parse_env(envp[i]);
		env = env_fill(env_tab[0], env_tab[1]);
		if (ft_strequ("HOME", env_tab[0]))
			all->home = ft_strdup(env_tab[1]);
		free_tb(&env_tab);
		ft_sh_push(all, env);
		i++;
	}
}

void	ft_sh_env(char **str, t_all *all)
{
	int status;

	if (!str[1])
		return (ft_print_env(all));
	if (!(ft_strequ("-i", str[1]) && str[2]))
		return ;
	if (ft_is_binary(str[2], all))
	{
		all->pid = fork();
		if (all->pid < 0)
			ft_sh_error(SYSPID, "\0");
		if (all->pid == 0)
		{
			if (execve(all->path, (str + 2), NULL) < 0)
			{
				ft_sh_exec_error(all->path);
				exit(1);
			}
		}
		else
			waitpid(all->pid, &status, WUNTRACED);
		ft_term_error(WTERMSIG(status));
	}
	else
		ft_sh_error(ENV_ERROR, str[2]);
}
