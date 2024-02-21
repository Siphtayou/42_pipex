/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:47:28 by agilles           #+#    #+#             */
/*   Updated: 2024/02/21 15:57:31 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*pipex_getenv(char *name, char **env)
{
	char	*possible_path;
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		possible_path = ft_substr(env[i], 0, j);
		if (ft_strcmp(possible_path, name) == 0)
		{
			free(possible_path);
			return (env[i] + j + i);
		}
		free(possible_path);
		i++;
	}
	return (NULL);
}

char	*cmd_path(char *cmd, char **env)
{
	char	*path;
	char	*exec;
	char	**allpath;
	char	**split_cmd;
	int		i;

	i = -1;
	allpath = ft_split(pipex_getenv("PATH", env), ':');
	split_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		path = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path, split_cmd[0]);
		free(path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			pipex_free_tab(split_cmd);
			return (exec);
		}
		free(exec);
	}
	pipex_free_tab(split_cmd);
	pipex_free_tab(allpath);
	return (cmd);
}
