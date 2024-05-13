/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:29:08 by ychiba            #+#    #+#             */
/*   Updated: 2024/05/13 17:32:06 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	setup_signal_handlers(void)
{
	struct sigaction	sa_int;

	sa_int.sa_handler = handle_sigint;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_int, NULL); // Ctrl-C
	signal(SIGQUIT, SIG_IGN); // Ctrl-\ を無視
}

t_env	*new_env_node(char *env_str)
{
	t_env	*node;
	char	*separator;
	int		name_len;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	separator = ft_strchr(env_str, '=');
	if (!separator)
	{
		free(node);
		return (NULL);
	}
	name_len = separator - env_str;
	node->env_name = malloc(name_len + 1);
	ft_strncpy(node->env_name, env_str, name_len);
	node->env_name[name_len] = '\0';
	node->env_val = strdup(separator + 1);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_env	*set_env_list(char **envp)
{
	t_env	*head;
	t_env	*tail;
	t_env	*new_node;

	head = NULL;
	tail = NULL;
	while (*envp)
	{
		new_node = new_env_node(*envp);
		if (!new_node)
		{
			perror("Failed to create env node");
			continue ;
		}
		if (tail)
		{
            tail->next = new_node;
            new_node->prev = tail;
		}
		else
			head = new_node;
		tail = new_node;
		envp++;
	}
	return (head);
}

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
	char	*line;
	int		status;

	args = NULL;
	setup_signal_handlers();
	status = 1;
	while (1)
	{
		line = readline("minishell> ");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (ft_strlen(line) > 0)
			add_history(line);
		args = malloc(sizeof(t_args));
		if (!args)
		{
			free(line);
			continue ;
		}
		args->argv = minishell_split(line);
		status = execute_com(args);
		if (status != 1)
			break ;
		free(line);
		ft_free_args(args);
	}
	return (status);
}

void print_env_list(t_env *env_list)
{
    t_env *current = env_list;
    while (current) {
        printf("Env Name: %s, Env Value: %s\n", current->env_name, current->env_val);
        current = current->next;
    }
}

int	main(int argc, char **argv, char **envp)
{
	int		status;
	// int		i = 0;
	(void)argc;
	(void)argv;
	status = 0;
	t_env *env_list = set_env_list(envp);
	status = main_loop();
    print_env_list(env_list);
    while (env_list)
	{
        t_env *next = env_list->next;
        free(env_list->env_name);
        free(env_list->env_val);
        free(env_list);
        env_list = next;
    }
	return (status);
}
