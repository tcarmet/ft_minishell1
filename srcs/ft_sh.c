/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:24:53 by tcarmet           #+#    #+#             */
/*   Updated: 2015/04/05 01:40:53 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
**	in this function we will parse the command line, in the first place we will
**	check if the argument given is a builtin, if not it will try to execute it.
*/

void	parse_cmd(char *cmd, t_all *all)
{
	char	**cmd_array;
	char	**cmd_all;
	int		i;

	i = 0;
	cmd_all = ft_strsplit(cmd, ';');
	free(cmd);
	while (cmd_all[i])
	{
		cmd_all[i] = ft_leave_tab(cmd_all[i]);
		cmd_array = ft_tild_split(ft_strsplit(cmd_all[i], ' '), all->home);
		if (cmd_array[0])
		{
			if (ft_is_builtin(cmd_array[0]))
				ft_exec_builtin(cmd_array, all);
			else if (ft_is_binary(cmd_array[0], all))
				ft_exec_binary(cmd_array, all);
			else
				ft_sh_error(SYSCALL, cmd_array[0]);
			ft_free_tb(&cmd_array);
		}
		i++;
	}
	ft_free_tb(&cmd_all);
}

/*
**	ft_put_prompt will print the prompt, getlogin is used for project bonus.
**	and also we use strrchr to print to current directory.
*/

int		ft_put_prompt(void)
{
	char	*pwd;
	char	*tmp;
	char	*log;

	log = getlogin();
	tmp = NULL;
	pwd = getcwd(tmp, 1024);
	ft_putstr("\033[32m[");
	ft_putstr(log);
	ft_putstr("]\033[00m");
	ft_putstr(" $> \033[34;01m");
	if (ft_strequ(pwd, "/"))
		ft_putstr("/");
	else
		ft_putstr(ft_strrchr(pwd, '/') + 1);
	ft_putstr("\033[00m : ");
	free(pwd);
	return (1);
}

pid_t	save_pid(pid_t pid)
{
	static pid_t	spid = 0;

	if (pid)
		spid = pid;
	return (spid);
}

/*
**	this function is called when a signal is catched and it will errase the
**	signal character.
*/
void	ft_control(int i)
{
	(void)i;
	if (save_pid(0) <= 0)
	{
		ft_putchar(8);
		ft_putchar(8);
		ft_putchar(32);
		ft_putchar(32);
		ft_putchar(8);
		ft_putchar(8);
		ft_putchar('\n');
		ft_put_prompt();
	}
}

/*
**	the main will in the first place check if there is a environment and then
**	it will stock the environment into the linked list. if no environment is 
**	given we will create a mini one.
**	once this step is done the program will enter into a infinite loop.
*/

int		main(int argc, char **argv, char **env)
{
	t_all	all;
	char	*line;

	(void)argc;
	(void)argv;
	line = NULL;
	ft_sh_init(&all);
	if (ft_sh_check_env(env, &all))
		ft_stock_env(env, &all);
	while (all.pid >= 0 && ft_put_prompt())
	{
		signal(SIGINT, ft_control);
		signal(SIGTSTP, ft_control);
		signal(SIGSTOP, ft_control);
		if (get_next_line(0, &line) > 0)
			parse_cmd(line, &all);
		else
		{
			if (line)
				free(line);
			line = NULL;
			all.pid = -1;
		}
	}
	return (0);
}
