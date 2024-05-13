/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:17:06 by ychiba            #+#    #+#             */
/*   Updated: 2024/05/07 17:43:59 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <signal.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_split
{
	int		count;
	int		i;
	int		j;
	int		k;
	char	**result;
}	t_split;

typedef struct s_args
{
	int		argc;
	char	**argv;
}	t_args;

typedef struct s_env
{
	char				*env_name;
	char				*env_val;
	struct s_env				*next;
	struct s_env				*prev;
}	t_env;

int		execute_com(t_args	*args);
int		exe_exit(t_args *args);
int		exe_chdir(t_args *args);
int		exe_pwd(t_args *args);
int		exe_echo(t_args args);
int		exe_env(void);
char	**minishell_split(char *s);

#endif // MINISHELL_H
