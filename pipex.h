/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:47:26 by agilles           #+#    #+#             */
/*   Updated: 2024/02/21 15:22:59 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "printf_libft/ft_printf.h"

char	*pipex_getenv(char *name, char **env);
char	*cmd_path(char *cmd, char **env);

void	exec(char *cmd, char **env);
void	pipex_free_tab(char **tab);
void	child_process(int *p_fd, char **av, char **env);
void	parent_process(int *p_fd, char **av, char **env);

int	pipex_error(char *error);

#endif
