/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:29:08 by ychiba            #+#    #+#             */
/*   Updated: 2024/04/30 19:06:50 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_args(t_args *args)
{
	int	i;

	i = 0;
	if (args)
	{
		if (args->argv)
		{
			while (args->argv[i] != NULL)
			{
				free(args->argv[i]);
				i++;
			}
			free(args->argv);
		}
		free(args);
	}
}

int	main_loop(void)
{
	t_args	*args;
	char	*input;
	int		status;

	args = NULL;
	status = 1;
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		if (ft_strlen(input) > 0)
			add_history(input);
		args = malloc(sizeof(t_args));
		if (!args)
		{
			free(input);
			continue ;
		}
		args->argv = minishell_split(input);
		status = execute_com(args);
		if (status != 1)
			break ;
		free(input);
		ft_free_args(args);
	}
	return (status);
}

int	main(void)
{
	int		status;

	status = 0;
	status = main_loop();
	return (status);
}
