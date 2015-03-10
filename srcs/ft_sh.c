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
	int j;

	i = 0;
	cmd_all = ft_strsplit(cmd, ';');
	while (cmd_all[i])
	{
		cmd_array = ft_strsplit(cmd_all[i], ' ');
		j = 0;
		while (cmd_array[j])
		{
			cmd_array[j] = ft_strlower(cmd_array[j]);
			if (ft_is_builtin(cmd_array[j]))
				ft_exec_builtin(cmd_array[j], all);
			// else if (IS_BINARY(cmd_array[0])
			// 	exec_binary(cmd_array);
			else
				ft_sh_error(SYSCALL, cmd_array[j]);
			j++;
		}
		i++;
	}
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
	// ft_print_env(&all);
	while (42)
	{
		ft_putstr("$> :");
		get_next_line(0, &line);
		parse_cmd(line, &all);		
	}
	return (0);
}

