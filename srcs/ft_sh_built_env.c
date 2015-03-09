/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_built_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 21:31:59 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/09 21:32:02 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_print_env(t_env	*tmp)
{
	while (tmp != NULL)
	{
		ft_putstr(tmp->var);
		ft_putchar('=');
		ft_putendl(tmp->value);
		tmp = tmp->next;
	}
}