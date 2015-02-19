/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:24:53 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/17 00:45:27 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_sh.h"

int		main(int argc, char **argv)
{
//	pid_t		father;
	char *str;
	

	if (argc == 1)
	{

		str = getcwd(argv[1], ft_strlen(argv[1]));
		ft_putstr(str);
		/*father = fork();
		if (father > 0)
		{
//			wait();
			printf("I M YOUR FATHER\n");
		}
		if (father == 0)
		{
			sleep(5);
			execve("/bin/ls", argv, NULL);
		}
		*/
	}
	return (0);
}
