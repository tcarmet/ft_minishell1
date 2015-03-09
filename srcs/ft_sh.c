/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:24:53 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/09 16:42:42 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_sh.h"

int		main(int argc, char **argv, char **env)
{
	t_all	all;
	char	*line;
	t_env	*tmp;

	(void)argv;
	(void)argc;
	line = NULL;
	// ft_sh_init(&all);
	ft_stock_env(env, &all);
	tmp = all.env;
	while (tmp->next != NULL)
	{
		ft_putstr(tmp->var);
		ft_putchar('=');
		ft_putendl(tmp->value);
		tmp = tmp->next;
	}
	/*while (42)
	{
		ft_putstr("$> :");
		get_next_line(0, &line);

		ft_putendl(line);
	}*/
	return (0);
}

