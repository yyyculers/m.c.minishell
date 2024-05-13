/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:49:41 by ychiba            #+#    #+#             */
/*   Updated: 2024/04/30 17:23:01 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	execute_com(t_args	*args)
{
	args->argc = 0;
	while (args->argv[args->argc] != NULL)
		args->argc++;
	if (args->argv[0] == NULL)
		return (1);
	if (ft_strncmp(args->argv[0], "exit", 5) == 0)
		return (exe_exit(args));
	if (ft_strncmp(args->argv[0], "cd", 3) == 0)
		return (exe_chdir(args));
	if (ft_strncmp(args->argv[0], "pwd", 4) == 0)
		return (exe_pwd(args));
	if (ft_strncmp(args->argv[0], "echo", 5) == 0)
		return (exe_echo(*args));
	if (ft_strncmp(args->argv[0], "env", 4) == 0)
		return (exe_env());
	// if (ft_strncmp(args->argv[0], "export", 7) == 0)
	// 	return (exe_export());
	// if (ft_strncmp(args->argv[0], "unset", 6) == 0)
	// 	return (exe_unset());
	return (1);
}
