/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 16:34:08 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/11 16:34:08 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	check_reserve(char **reserve, char ***line)
{
	char	*ptr;
	char	*tmp;

	tmp = NULL;
	if (*reserve == NULL)
		*reserve = (char*)malloc(sizeof(char) * 2);
	if (*reserve)
		if ((ptr = ft_strchr(*reserve, '\n')))
		{
			*ptr = '\0';
			**line = ft_strdup(*reserve);
			tmp = *reserve;
			*reserve = ft_strdup(ptr + 1);
			free(tmp);
			return (1);
		}
	return (0);
}

static int	what_return(int ret, char **reserve, char ***line)
{
	if (ret < 0)
		return (-1);
	if (*reserve == NULL)
		return (0);
	**line = ft_strdup(*reserve);
	return (0);
}

static int	econom(char **reserve, char **ptr, char **ptr2, char ***line)
{
	char	*tmp;

	**ptr = '\0';
	**line = ft_strjoin(*reserve, *ptr2);
	tmp = *reserve;
	*reserve = ft_strdup(*ptr + 1);
	free(tmp);
	free(*ptr2);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*reserve[256];
	char		*ptr[3];
	int			ret;

	if (!line)
		return (-1);
	ptr[2] = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	if ((check_reserve(&reserve[fd], &line)) == 1)
	{
		free(ptr[2]);
		return (1);
	}
	while ((ret = read(fd, ptr[2], BUFF_SIZE)) > 0)
	{
		ptr[2][ret] = '\0';
		ptr[1] = ft_strchr(ptr[2], '\n');
		if (ptr[1])
			if ((econom(&reserve[fd], &ptr[1], &ptr[2], &line) == 1))
				return (1);
		ptr[0] = reserve[fd];
		reserve[fd] = ft_strjoin(reserve[fd], ptr[2]);
		free(ptr[0]);
	}
	return (what_return(ret, &reserve[fd], &line));
}
