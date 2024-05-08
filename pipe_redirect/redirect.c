/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:51:54 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/04 22:53:01 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void redirect_input(const char *filename) {
	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	if (dup2(fd, STDIN_FILENO) == -1) {
		perror("dup2");
		exit(EXIT_FAILURE);
	}

	close(fd);
}
void redirect_output(const char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

void redirect_append(const char *filename) {
	int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	if (dup2(fd, STDOUT_FILENO) == -1) {
		perror("dup2");
		exit(EXIT_FAILURE);
	}

	close(fd);
}


void execute_here_document(const char *text) {
    size_t len = strlen(text);
    if (write(STDOUT_FILENO, text, len) != len) {
        perror("write");
        exit(EXIT_FAILURE);
    }
}
