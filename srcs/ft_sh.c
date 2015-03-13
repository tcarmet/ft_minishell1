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

void	parse_cmd(char *cmd, t_all *all)
{
	char **cmd_array;
	char **cmd_all;
	int i;

	i = 0;
	cmd_all = ft_strsplit(cmd, ';');
	free(cmd);
	while (cmd_all[i])
	{	
		cmd_all[i] = ft_leave_tab(cmd_all[i]);
		cmd_array = ft_strsplit(cmd_all[i], ' ');
		if (cmd_array[0])
		{
			cmd_array[0] = ft_strlower(cmd_array[0]);
			if (ft_is_builtin(cmd_array[0]))
				ft_exec_builtin(cmd_array, all);
			else if (ft_is_binary(cmd_array[0], all))
				ft_exec_binary(cmd_array, all);
			else
				ft_sh_error(SYSCALL, cmd_array[0]);
			free(cmd_array);
		}
		i++;
	}
	free(cmd_all);
}

int		main(int argc, char **argv, char **env)
{
	t_all	all;
	char	*line;

	(void)argv;
	(void)argc;
	line = NULL;
	ft_sh_init(&all);
	ft_stock_env(env, &all);
	while (all.pid >= 0)
	{
		signal(SIGINT, SIG_IGN);
		ft_putstr("$> : ");
		if (get_next_line(0, &line) > 0)
			parse_cmd(line, &all);
		else
		{
			free(line);
			all.pid = -1;
		}
	}
	return (0);
}
