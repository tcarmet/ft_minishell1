/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 17:50:00 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/21 13:17:18 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
**	This function will put the environment into an array of string
**	we will use this array in execve.
*/
void	ft_env_to_array(t_all *all)
{
	t_env	*tmp;
	int		count;
	int		len;

	count = 0;
	tmp = all->env;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	all->array = (char **)malloc(sizeof(char *) * (count + 1));
	count = 0;
	tmp = all->env;
	while (tmp)
	{
		len = 0;
		len = ft_strlen(tmp->var);
		len += ft_strlen(tmp->value);
		all->array[count] = ft_strjoin(tmp->var, "=");
		all->array[count] = ft_strjoin_free(all->array[count], tmp->value);
		count++;
		tmp = tmp->next;
	}
	all->array[count] = NULL;
}

/*
**	in this function we will see with access if we have the rights of 
**	execution of the requested file.
*/

int		ft_check_binary(char **split, struct stat stat, t_all *all, char *str)
{
	int	i;

	i = 0;
	(void)stat;
	while (split[i])
	{
		all->path = ft_strjoin(split[i], "/");
		all->path = ft_strjoin_free(all->path, str);
		if (access(all->path, X_OK) == 0)
		{
			ft_free_tb(&split);
			return (1);
		}
		if (all->path)
			free(all->path);
		i++;
	}
	return (0);
}

/*
**	ft_is_binary while in the first place check if the file we want to execute
**	is in the current directory. "./a.out". 
**	Otherwise it will get the PATH value split it and stock to right path 
**	to the binary file into all->path, and we will use it into execve.
*/

int		ft_is_binary(char *str, t_all *all)
{
	char			**split;
	t_env			*tmp;
	struct stat		s;

	tmp = all->env;
	while (tmp && tmp->next && ft_strequ("PATH", tmp->var) != 1)
		tmp = tmp->next;
	if ((str[0] == '.' || str[0] == '/') && lstat(str, &s) >= 0)
	{
		all->path = ft_strdup(str);
		tmp = NULL;
		return (1);
	}
	else if (str[0] == '.' || str[0] == '/')
		return (0);
	if (!tmp)
		return (0);
	split = ft_strsplit(tmp->value, ':');
	if (ft_check_binary(split, s, all, str))
		return (1);
	ft_free_tb(&split);
	tmp = NULL;
	return (0);
}

void	ft_sh_exec_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": Permission denied.", 2);
}

/*
**	in this function we will execute the program called and wait till the processus
**	is finished to restore the shell. if we have no rights or so, ft_sh_exec_error
**	is called. Also if the program we execute happen to crash (bus error, Segmentation
**	fault...) ft_term_error will catch the right signal and show the right error to the
**	user.
*/

void	ft_exec_binary(char **str, t_all *all)
{
	int		status;

	if (all->env)
		ft_env_to_array(all);
	all->pid = fork();
	save_pid(all->pid);
	if (all->pid < 0)
		ft_sh_error(SYSPID, "\0");
	if (all->pid == 0)
	{
		if (execve(all->path, str, all->array) < 0)
		{
			ft_sh_exec_error(all->path);
			exit(-1);
		}
	}
	else
		waitpid(all->pid, &status, WUNTRACED);
	ft_term_error(WTERMSIG(status));
	save_pid(-1);
	ft_free_tb(&all->array);
	free(all->path);
}
