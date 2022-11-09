/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_check_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:29:09 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/09 13:34:46 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int search_path(char **env)
{
	int i;

	i = -1;
	while(env[++i])
	{
		if(ft_strncmp(env[i], "PATH=", 5) == 0)
			return i;
	}
	return -1;
}

static int check_if_path(char *cmd)
{
	int i;

	i = -1;
	while(cmd[++i])
	{
		if(cmd[i] == '/')
			return (1);
	}
	return (0);
}

int  check_permission(char *cmd)
{
	if (access(cmd, F_OK) == -1)
		return (ft_putstr_fd("No such file or directory\n", 2), -1);
	if (access(cmd, R_OK) == -1)
		return (ft_putstr_fd("Minishell :Permission denied\n", 2), -2);
	if (access(cmd, X_OK) == -1)
		return (ft_putstr_fd("Minishell :Permission denied\n", 2), -3);
	return (1);
}

static int search_cmd(char *cmd, char *env, char **path)
{
	t_sub	sub;
	char	*subtr;
	char	*jointr;

	sub.start = 5;
	sub.end = 5;
	while (env[sub.end])
	{
		if (env[sub.end] == ':')
		{
			subtr = ft_substr(env, sub.start, sub.end - sub.start + 1);
			if (!subtr)
				return ft_putstr_fd("allocation failed\n", 2), -1;
			subtr[sub.end - sub.start] = '/';
			sub.start = sub.end + 1;
			jointr = ft_strjoin(subtr, cmd);
			if (!jointr)
				return free(subtr), ft_putstr_fd("allocation failed\n", 2), -1;
			if(access(jointr, F_OK) != -1)
				return(free(subtr), *path = jointr, 1);
			free(jointr);
			free(subtr);
		}
		sub.end++;
	}
	return (-1);
}

int	print_to_error(char *str, char *error, int re)
{
	ft_putstr_fd("minishell: ", 2);
	if (str)
		ft_putstr_fd(str, 2);
	ft_putendl_fd(error, 2);
	return re;
}

static int check_if_dir(char *path)
{
	DIR *dir;

	dir = opendir(path);
	if (dir)
		return  print_to_error(path, ": is a directory", -1);
	return 1;
}

int check_cmd(t_node *node, t_env *env, char **path)
{
	int i;

	if (check_if_path(node->token.token))
	{
		
		(*path) = node->token.token;
		if (check_permission(*path) < 0)
			return -1;
		return check_if_dir(*path);
	}
	i = search_path(env->env_tab);
	if (i == -1 || search_cmd(node->token.token, env->env_tab[i], path) ==  -1)
		return ft_putstr_fd("command not found\n", 2), -4;
	return (check_permission(*path));
}
