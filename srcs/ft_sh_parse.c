/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 17:53:21 by tcarmet           #+#    #+#             */
/*   Updated: 2015/04/05 18:37:16 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	**ft_parse_env(char *env)
{
	char	**env_tab;
	int		i;

	env_tab = (char **)malloc(sizeof(char *) * 3);
	i = 0;
	while (env[i] != '=')
		i++;
	env_tab[0] = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (env[i] != '=')
	{
		env_tab[0][i] = env[i];
		i++;
	}
	env_tab[0][i] = '\0';
	i++;
	env_tab[1] = ft_strdup(env + i);
	env_tab[2] = NULL;
	return (env_tab);
}

char	**ft_tild_split(char **split, char *home)
{
	int		i;
	char	*tmp;

	i = 0;
	while (split[i])
	{
		if (split[i][0] == '~')
		{
			tmp = split[i];
			split[i] = ft_strjoin(home, tmp + 1);
			free(tmp);
		}
		i++;
	}
	return (split);
}
