/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:54:50 by tcoppin           #+#    #+#             */
/*   Updated: 2015/03/10 14:55:05 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*n;
	int		i;
	int		j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	n = (char *)malloc(sizeof(char) * (i + j + 1));
	i = 0;
	while (s1[i])
	{
		n[i] = s1[i];
		i++;	
	}
	free(s1);
	j = 0;
	while (s2[j])
	{
		n[i + j] = s2[j];
		j++;	
	}
	n[i + j] = '\0';
	return (n);
}

void	free_tb(char ***s)
{
	int	i;

	i = 0;
	while ((*s)[i])
	{
		free((*s)[i]);
		(*s)[i] = NULL;
		i++;
	}
	free(*s);
	*s = NULL;
}

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

int		ft_is_binary(char *str, t_all *all)
{
	char **split;
	t_env	*tmp;
	int		i;
	struct stat	stat;

	i = 0;
	tmp = all->env;
	while (tmp->next && ft_strequ("PATH", tmp->var) != 1)
		tmp = tmp->next;
	split = ft_strsplit(tmp->value, ':');
	while (split[i])
	{
		all->path = ft_strjoin(split[i], "/");
		all->path = ft_strjoin_free(all->path, str);
		if (lstat(all->path, &stat) >= 0)
		{
			free_tb(&split);
			tmp = NULL;
			return (1);
		}
		i++;
	}
	free_tb(&split);
	tmp = NULL;
	return (0);
}

void	ft_exec_binary(char **str, t_all *all)
{	
	pid_t pid;

	ft_env_to_array(all);
	pid = fork();
	if (pid < 0)
		ft_sh_error(SYSPID, "\0");
	if (pid == 0)
	{
		if (execve(all->path, str, all->array) < 0)
			ft_sh_error(EXEC_ERROR, "\0");
	}
	else
	{
		wait(&pid);
		free_tb(&all->array);
	}
}
