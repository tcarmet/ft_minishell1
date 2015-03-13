/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:54:50 by tcoppin           #+#    #+#             */
/*   Updated: 2015/03/12 15:24:42 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_env_to_array(t_all *all)
{
	t_env	*tmp;
	int		count;
	int		len;

	count = 0;
	tmp = all->env;
	while (tmp->next)
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

int		ft_check_binary(char **split, struct stat stat, t_all *all, char *str)
{
	int i;

	i = 0;	
	while (split[i])
	{
		all->path = ft_strjoin(split[i], "/");
		all->path = ft_strjoin_free(all->path, str);
		if (lstat(all->path, &stat) >= 0)
		{
			free_tb(&split);
			return (1);
		}
		if (all->path)
			free(all->path);
		i++;
	}
	return (0);
}

int		ft_is_binary(char *str, t_all *all)
{
	char **split;
	t_env	*tmp;
	struct stat	stat;

	tmp = all->env;
	while (tmp->next && ft_strequ("PATH", tmp->var) != 1)
		tmp = tmp->next;
	if ((str[0] == '.' || str[0] == '/') && lstat(str, &stat) >= 0)
	{
		all->path = ft_strdup(str);
		tmp = NULL;
		return (1);
	}
	else if (str[0] == '.' || str[0] == '/')
		return (0);
	split = ft_strsplit(tmp->value, ':');
	if (ft_check_binary(split, stat, all, str))
		return (1);
	free_tb(&split);
	tmp = NULL;
	return (0);
}	

void	ft_exec_binary(char **str, t_all *all)
{	
	ft_env_to_array(all);
	all->pid = fork();
	if (all->pid < 0)
		ft_sh_error(SYSPID, "\0");
	if (all->pid == 0)
	{
		if (execve(all->path, str, all->array) < 0)
		{
			ft_sh_error(EXEC_ERROR, "\0");
			exit(-1);
		}
	}
	else
		wait(&all->pid);
}
