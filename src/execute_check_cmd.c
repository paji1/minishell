/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_check_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:29:09 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/17 18:53:10 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*search_path(t_env *env)
{
	t_env_node	*node;

	node = env->head;
	while (node)
	{
		if (ft_strncmp(node->key, "PATH", 4) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

static int check_if_path(char *cmd)
{
	int i;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '/')
			return (1);
	}
	return (0);
}

int	check_permission(char *cmd)
{
	if (access(cmd, F_OK) == -1)
		return (print_to_error(cmd," No such file or directory", -1));
	if (access(cmd, R_OK) == -1)
		return (print_to_error(NULL, "Permission denied", -2));
	if (access(cmd, X_OK) == -1)
		return (print_to_error(NULL, "Permission denied", -3));
	return (1);
}

static int	search_cmd(char *cmd, char *env, char **path)
{
	t_sub	sub;
	char	*subtr;
	char	*jointr;

	sub.start = 0;
	sub.end = 0;
	while (env[sub.end])
	{
		if (env[sub.end] == ':')
		{
			subtr = ft_substr(env, sub.start, sub.end - sub.start + 1);
			if (!subtr)
				return (ft_putstr_fd("allocation failed\n", 2), -1);
			subtr[sub.end - sub.start] = '/';
			sub.start = sub.end + 1;
			jointr = ft_strjoin(subtr, cmd);
			if (!jointr)
				return (free(subtr), ft_putstr_fd("allocation failed\n", 2), -1);
			if (access(jointr, F_OK) != -1)
				return (free(subtr), *path = jointr, 1);
			free(jointr);
			free(subtr);
		}
		sub.end++;
	}
	return (-1);
}

static int	check_if_dir(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir)
		return (print_to_error(path, ": is a directory", -1));
	return (1);
}

void	print_cnf(char *key)
{
	ft_putstr_fd(key, 2);
	ft_putendl_fd(": command not found", 2);
}

int	check_cmd(t_node *node, t_env *env, char **path)
{
	char	*key;

	if (check_if_path(node->token.token))
	{
		(*path) = node->token.token;
		if (check_permission(*path) < 0)
			return (-1);
		return (check_if_dir(*path));
	}
	key = search_path(env);
	if (!key)
		return (print_cnf(node->token.token), -4);
	if (search_cmd(node->token.token, key, path) == -1)
		return (print_cnf(node->token.token), -4);
	return (check_permission(*path));
}
