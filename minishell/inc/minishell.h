/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:17:06 by ychiba            #+#    #+#             */
/*   Updated: 2024/04/25 18:07:02 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../srcs/libft/libft.h"

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

typedef struct s_return
{
	int	retu;
}	t_return;

int		execute_com(t_args	*args);
int		exe_exit(t_args *args);
int		exe_chdir(t_args *args);
int		exe_pwd(t_args *args);
char	**minishell_split(char *s);

#endif // MINISHELL_H
