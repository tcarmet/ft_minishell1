/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:03:27 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/13 21:13:45 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H
# include "libft.h"
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;

}				t_env;

typedef struct	s_all
{
	t_env		*env;
	char		*path;
	char		**array;
	pid_t		pid;
	int			prompt;
}				t_all;

typedef enum	e_error
{
	SYSCALL = 1,
	SYSPID,
	EXEC_ERROR,
	ARG_ENV,
	UNSET_ARG,
	ENV_ERROR,
}				t_error;

/*
**	ft_sh_init.c
*/
void			ft_sh_init(t_all *all);
int				ft_sh_check_env(char **env, t_all *all);
/*
**	ft_sh_env.c
*/
t_env			*env_init(void);
t_env			*env_fill(char *var, char *value);
void			ft_sh_push(t_all *all, t_env *env);
void			ft_stock_env(char **env, t_all *all);
void			ft_sh_env(char **str, t_all *all);
/*
** ft_sh_misc.c
*/
char			*ft_strlower(char *str);
void			ft_sh_error(int i, char *str);
char			*ft_leave_tab(char *cmd);
size_t			ft_strlen_tab(char **tab);
void			free_tb(char ***s);
/*
** ft_sh_parse.c
*/
char			**ft_parse_env(char *env);
/*
**	ft_sh_built_env.c
*/
void			ft_print_env(t_all	*all);
void			ft_sh_setenv(char **str, t_all *all);
int				ft_setenv_check(char **str, t_all *all);
int				ft_sh_unsetenv(char **str, t_all *all);
void			ft_sh_list_search(t_env *prev, char **str, int i);
/*
**	ft_sh.c
*/
int				ft_put_prompt(void);
void			ft_control(int i);
void			parse_cmd(char *cmd, t_all *all);
/*
**	ft_sh_builtin.c
*/
int				ft_is_builtin(char *str);
void			ft_exec_builtin(char **str, t_all *all);
void			ft_sh_exit(char **str);
/*
**	ft_sh_binary.c
*/
int				ft_is_binary(char *str, t_all *all);
void			ft_exec_binary(char **str, t_all *all);
void			ft_env_to_array(t_all *all);
int				ft_check_binary(char **split, struct stat stat, \
				t_all *all, char *str);
/*
**	ft_sh_cd.c
*/
void			ft_sh_cd(char **str, t_all *all);
#endif
