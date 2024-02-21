/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:47:21 by agilles           #+#    #+#             */
/*   Updated: 2024/02/21 15:56:35 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex_error(char *error)
{
	ft_printf("%s\n", error);
	return (1);
}

void	exec(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	path = cmd_path(split_cmd[0], env);
	if (execve(path, split_cmd, env) == -1)
	{
		ft_printf("pipex command not found : %s", split_cmd[0]);
		pipex_free_tab(split_cmd);
		exit (0);
	}
}

void	child_process(int *p_fd, char **av, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
		exit (pipex_error("fail when open a file"));
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(av[2], env);
}

void	parent_process(int *p_fd, char **av, char **env)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit (pipex_error("fail when open a file"));
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	(void)av;
	(void)env;
	if (ac != 5)
		return (pipex_error("Argument Error"));
	if (pipe(p_fd) == -1)
		return (pipex_error("Pipe Error"));
	pid = fork();
	if (pid == -1)
		return (pipex_error("Fork Error"));
	if (!pid)
		child_process(p_fd, av, env);
	parent_process(p_fd, av, env);
}
