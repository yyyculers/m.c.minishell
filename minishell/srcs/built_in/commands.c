/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:49:41 by ychiba            #+#    #+#             */
/*   Updated: 2024/06/03 22:54:54 by ychiba           ###   ########.fr       */
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
	if (ft_strncmp(args->argv[0], "grep", 3) == 0)
	{
		printf("grep\n");
		args->argv[0] = "/usr/bin/grep";
		return (execve(args->argv[0], args->argv, NULL));
	}
	if (ft_strncmp(args->argv[0], "ls", 3) == 0)
	{
		args->argv[0] = "/bin/ls";
		return (execve(args->argv[0], args->argv, NULL));
	}
	return (1);
}

// 実行のサンプル
// #include <unistd.h>
// #include <stdio.h>

// int main() {
//     char *cmd = "/bin/ls";  // ls コマンドのパス　←ここが問題　網羅的に実行したい　下のコード
//     char *argv[] = {cmd, "-l", NULL};  // 引数の配列、ここに `-l` オプションを含む
//     char *envp[] = {NULL};  // 環境変数の配列、ここでは何も渡さない

//     if (execve(cmd, argv, envp) == -1) {
//         perror("execve failed");
//         return 1;
//     }
//     return 0;  // execve が成功した場合、ここには到達しない
// }
//
// 簡単な実行フロー
//
// 環境変数PATHから順に（local/bin）などの後にコマンドを挿入　（実行プログラムのフルパス）
//　-->実行可能かチェック　access
//　可能なら実行
//
// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>

// int main() {
//     char *path_env = getenv("PATH");
//     if (!path_env) {
//         write(2, "No PATH variable found.\n", 24);
//         return 1;
//     }

//     char *path = path_env;
//     char *end;
//     char full_path[256];  // このサイズは環境によって調整する

//     while ((end = strchr(path, ':')) != NULL) {
//         if (end - path < 255) {
//             memcpy(full_path, path, end - path);
//             full_path[end - path] = '/';
//             strcpy(full_path + (end - path) + 1, "ls");
//             if (access(full_path, X_OK) == 0) {
//                 char *argv[] = {"ls", NULL};
//                 execve(full_path, argv, NULL);
//                 // execve が成功した場合、ここには戻らない
//             }
//         }
//         path = end + 1;
//     }

//     // 最後のパスセグメントをチェック
//     strcpy(full_path, path);
//     strcat(full_path, "/ls");
//     if (access(full_path, X_OK) == 0) {
//         char *argv[] = {"ls", NULL};
//         execve(full_path, argv, NULL);
//     }

//     write(2, "Command not found.\n", 19);
//     return 1;
// }
