/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 22:31:02 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/26 22:47:25 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

typedef struct t_list s_env
{
	char *var;
	char *content;
   struct s_env *next;	
} 					t_env;

int		main(int ac, char **av, char **env)
{
	t_list 	*env_list;
	char 	*cmd;

	
	env_list = env_to_list(env);
	while(42)
	{
		print_prompt();
		get_next_line(0, &cmd);
		parse_cmd(cmd);
		ft_strdel(cmd);
	}
	return (0);
}

void	parse_cmd(char *cmd)
{
	char **cmd_array;
	char **cmd_all;
	int i;

	i = 0;
	cmd_all = ft_strsplit(cmd, ';');
	while (cmd_all[i])
	{
		cmd_array = ft_strsplit(cmd_all[i], ' ');
		i++;
	}
	if (IS_BUILTIN(cmd_array[0]))
		exec_builtin(cmd_array[0]);
	else if (IS_BINARY(cmd_array[0])
		exec_binary(cmd_array);
	else
		ft_putstr_fd("command not found", 2);
}

void	exec_binary(char **cmd)
{
	pid_t pid;
	char **env;

	env = env_to_array(t_list *env);
	pid = fork();
	if (pid < 0)
		error;
	if (pid == 0) //processus fils
	{
		execve(PATH, cmd_array, env);
	}
	else
		wait(NULL);
}
