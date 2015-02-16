/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:57:19 by tcarmet           #+#    #+#             */
/*   Updated: 2014/11/27 13:49:15 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_mallocwords(char const *s, char c, int *start)
{
	int		size;
	size_t	nbwords;
	int		i;
	char	**split;

	if (s == NULL)
		return (NULL);
	*start = -1;
	size = ft_strlen(s);
	nbwords = 0;
	i = 0;
	while (i < (size - 1))
	{
		if (s[i] == c && s[i + 1] != c)
			nbwords++;
		i++;
	}
	split = (char **)malloc(sizeof(*split) * (nbwords + 1));
	return (split);
}

static	void	ft_initvar(int *start, size_t *nbelem)
{
	*start = -1;
	*nbelem = 0;
}

static	void	test(char const *s, size_t *nbelem, int *start, int *i)
{
	(*nbelem)++;
	(*start == -1 && s[*i] != '\0') ? (*start = *i) : *start;
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**split;
	size_t	nbelem;

	if (!(split = ft_mallocwords(s, c, &start)))
		return (NULL);
	j = 0;
	i = 0;
	nbelem = 0;
	while (s[i])
	{
		if (s[i] != c || s[i] == '\0')
			test(s, &nbelem, &start, &i);
		if ((s[i] == c || s[i + 1] == '\0') && start >= 0)
		{
			split[j] = ft_strnew(nbelem);
			split[j++] = ft_strsub(s, start, nbelem);
			ft_initvar(&start, &nbelem);
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
