/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:12:15 by guilmira          #+#    #+#             */
/*   Updated: 2021/11/19 12:04:22 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

# include <stdio.h>

# define ARG "Incorrect arguments\n"
# define MSG "Pipe function failure\n"
# define GNL_ERROR "Problem with GNL\n"

void ft_shut(char *str, int i);
int process_origin(int fd[2]);
int process_son(int fd[2], char *path);
int	parser(int argc, char *argv[]);
#endif