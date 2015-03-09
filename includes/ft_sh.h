/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:03:27 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/17 00:45:49 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H
# include "libft.h"
# include <sys/wait.h>

typedef struct	s_env
{
	char *var;
	char *value;
	struct s_env *next;

}				t_env;

typedef struct	s_all
{
	t_env		*env;
}				t_all;



/*
**	ft_sh_init.c
*/
void			ft_sh_init(t_all *all);
/*
**	ft_sh_env.c
*/
t_env			*env_init(void);
t_env			*env_fill(char *var, char *value);
void			ft_sh_push(t_all *all, t_env *env);
void			ft_stock_env(char **env, t_all *all);
/*
** ft_sh_misc.c
*/
char			*ft_strlower(char *str);
/*
** ft_sh_parse.c
*/
char			**ft_parse_env(char *env);
#endif 
