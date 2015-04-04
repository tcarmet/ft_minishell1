/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_built_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 21:31:59 by tcarmet           #+#    #+#             */
/*   Updated: 2015/04/05 00:52:32 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
**	this function will print the environment.
*/
void	ft_print_env(t_all *all)
{
	t_env	*tmp;

	tmp = all->env;
	while (tmp != NULL)
	{
		if (tmp->var)
		{
			ft_putstr(tmp->var);
			ft_putchar('=');
			if (tmp->value)
				ft_putendl(tmp->value);
			else
				ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

/*
**	this function is part of the setenv builtin and will check if
**	the env that we are setting already exist, and will replace the 
**	value if it is required.
*/
int		ft_setenv_check(char **str, t_all *all)
{
	t_env	*tmp;

	tmp = all->env;
	while (tmp)
	{
		if (ft_strequ(tmp->var, str[1]))
		{
			free(tmp->value);
			if (str[2])
				tmp->value = ft_strdup(str[2]);
			else
				tmp->value = ft_strdup("\0");
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

/*
**	ft_sh_setenv is the main function of the setenv builtin and it 
**	will set the environment and put it into the linked list.
*/
void	ft_sh_setenv(char **str, t_all *all)
{
	t_env	*tmp;
	size_t	len;

	len = ft_strlen_tab(str);
	if (len == 1)
		ft_print_env(all);
	else if (len > 3)
		ft_sh_error(ARG_ENV, "\0");
	else if (ft_setenv_check(str, all))
		;
	else if (len <= 2)
	{
		tmp = env_fill(str[1], "\0");
		ft_sh_push(all, tmp);
	}
	else
	{
		tmp = env_fill(str[1], str[2]);
		ft_sh_push(all, tmp);
	}
}

void	ft_sh_list_search(t_env *prev, char **str, int i)
{
	t_env	*tmp;

	tmp = prev->next;
	while (tmp != NULL)
	{
		if (ft_strequ(tmp->var, str[i]))
		{
			prev->next = tmp->next;
			free(tmp->var);
			free(tmp->value);
			free(tmp);
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

/*
**	ft_sh_unsetenv is the main function of the unsetenv built in, and 
**	it will search into the the linked list the argument that we are looking
**	to unset, and it will free him.
*/
int		ft_sh_unsetenv(char **str, t_all *all)
{
	t_env	*prev;
	int		i;

	i = 1;
	if (!str[i])
		ft_sh_error(UNSET_ARG, "\0");
	if (!all->env)
		return (0);
	while (str[i])
	{
		prev = all->env;
		if (ft_strequ(prev->var, str[i]))
		{
			all->env = prev->next;
			free(prev->var);
			free(prev->value);
			free(prev);
		}
		ft_sh_list_search(prev, str, i);
		prev = NULL;
		i++;
	}
	return (0);
}
