/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 05:17:34 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/19 02:18:42 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	go_to_home(t_env *env)
{
	char		**path;
	t_env_node	*node;

	path = NULL;
	node = env->head;
	while (node)
	{
		if (!ft_strncmp(node->key, "HOME", 4))
		{
			path = malloc(3 * sizeof(char *));
			path[0] = ft_strdup("cd");
			path[1] = ft_strdup(node->value);
			path[2] = NULL;
			ft_cd(path, env);
			free_tab(path);
			return (0);
		}
		node = node->next;
	}
	return (ft_putendl_fd("minishell: cd: HOME not set", 2), 1);
}

int	ft_cd(char **cmd, t_env *env)
{
	char	newpath[PATH_MAX];
	char	oldpath[PATH_MAX];
	DIR		*dir;

	ft_bzero(newpath, PATH_MAX);
	ft_bzero(oldpath, PATH_MAX);
	if (!cmd[1])
		return (go_to_home(env));
	if (cmd[1])
	{
		dir = opendir(cmd[1]);
		if (dir == NULL)
			return (perror("mnishell"), 1);
		if (!getcwd(oldpath, PATH_MAX))
		{
			if (!ft_strcmp("..", cmd[1]))
				return add_or_change_value(env, ft_strdup("PWD"), ft_strjoin(get_value(env, "OLDPWD"), ft_strjoin("/", cmd[1]))), 1; // free getvalue free ft_trjoin;
			return (perror("minishell"), closedir(dir), 1);
		}
		add_or_change_value(env, ft_strdup("OLDPWD"), ft_strdup(oldpath));
		if (chdir(cmd[1]) == -1)
			return (closedir(dir), perror("mnishell chdir"), 1);
		if (!getcwd(newpath, PATH_MAX))
			return (closedir(dir), 1);
		add_or_change_value(env, ft_strdup("PWD"), ft_strdup(newpath));
		if (closedir(dir) == -1)
			return (perror("mnishell closeder"), 1);
	}
	return (0);
}
