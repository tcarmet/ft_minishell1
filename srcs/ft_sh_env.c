/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:56:18 by tcoppin           #+#    #+#             */
/*   Updated: 2015/03/09 17:56:19 by tcoppin          ###   ########.fr       */
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
		free(env_tab);
		ft_sh_push(all, env);
		i++;
	}
}

