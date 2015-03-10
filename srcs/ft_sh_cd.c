/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 16:39:01 by tcoppin           #+#    #+#             */
/*   Updated: 2015/03/10 16:39:02 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_sh_cd(char **str, t_all *all)
{
	char 	*pwd;
	t_env	*tmp;

	tmp = all->env;
	while (tmp->next != NULL && ft_strequ("PWD", tmp->var) != 1)
		tmp = tmp->next;
	pwd = ft_strdup(tmp->value);
	

}