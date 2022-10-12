#include "minishell.h"

static int search_path(char **env)
{
	int i;

	i = -1;
	while(env[++i])
	{
		if(strncmp(env[i], "PATH=", 5) == 0)
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

static int  check_permission(char *cmd)
{
	if (access(cmd, F_OK) == -1)
		return (ft_putstr_fd("No such file or directory\n", 2), -1);
	if (access(cmd, R_OK | W_OK) == -1)
		return (ft_putstr_fd("Permission denied\n", 2), -2);
	if (access(cmd, X_OK) == -1)
		return (ft_putstr_fd("Permission denied\n", 2), -3);
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
				return(free(subtr), *path = jointr , 1);
			free(subtr);
			free(jointr);
			ft_putstr_fd(jointr, 2);
		}
		sub.end++;
	}	
	return (0);
}

int check_cmd(t_node *node, char **env, char **path)
{
	int i;

	if (check_if_path(node->token.token))
	{
		(*path) = node->token.token;
		return (check_permission(node->token.token));
	}
	i = search_path(env);
	if (i == -1 || search_cmd(node->token.token, env[i], path) ==  -1)
		return ft_putstr_fd("command not found\n", 2), -4;
	return (check_permission(*path));
}
