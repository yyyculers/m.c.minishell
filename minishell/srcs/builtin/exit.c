/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:19:28 by ychiba            #+#    #+#             */
/*   Updated: 2024/04/25 18:03:33 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_exit_args(char **argv)
{
	int	i;

	i = 0;
	if (argv[1] == NULL)
		return (0);
	while (argv[1][i] != '\0')
	{
		if (ft_isdigit(argv[1][i]) != 1)
		{
			printf("exit\n");
			printf("minishell: exit: %s: numeric argument required\n", argv[1]);
			return (255);
		}
		i++;
	}
	return (0);
}

int	exe_exit(t_args *args)
{
	if (args->argc > 2)
	{
		printf("exit\n");
		printf("minishell: exit: too many arguments\n");
		return (1);
	}
	if (check_exit_args(args->argv) == 255)
		return (0);
	printf("exit");
	exit (EXIT_SUCCESS);
}
