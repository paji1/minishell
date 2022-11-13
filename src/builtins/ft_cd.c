/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 05:17:34 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/13 09:43:51 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	go_to_home(t_env *env, char **cmd)
{
	int			i;
	char		**path;
	t_env_node	*node;

	i = -1;
	path = NULL;
	node = env->head;
	while (node)
	{
		if (!ft_strncmp(node->key, "HOME", 4))
		{
			path = malloc(2 * sizeof(char *));
			path[0] = ft_strdup("cd");
			path[1] = ft_strdup(node->value);
			ft_cd(path, env);
			while (++i < 2)
				free(path[i]);
			free(path);
			return (0);
		}
		node = node->next;
	}
	return (ft_putendl_fd("minishell: cd: HOME not set", 2), -1);
}

int	ft_cd(char  **cmd, t_env *env)
{
	char newpath[PATH_MAX];
	char oldpath[PATH_MAX];
	DIR *dir;

	ft_bzero(newpath, PATH_MAX);
	ft_bzero(oldpath, PATH_MAX);
	
	if (!cmd[1])
		go_to_home(env, cmd);
	if (cmd[1])
	{
		dir = opendir(cmd[1]);
		if (dir == NULL)
			return (perror("mnishell"), -1);
		if (readdir(dir) == NULL)
			return (perror("reddir"), -1);
		getcwd(oldpath, PATH_MAX);
		if (!getcwd(oldpath, PATH_MAX))
			return closedir(dir), -4;
		add_or_change_value(env, "OLDPWD", ft_strdup(oldpath));
		if (chdir(cmd[1]) == -1)
			return closedir(dir), perror("mnishell chdir"), -2;
		if (!getcwd(newpath, PATH_MAX))
			return closedir(dir), -4;
		add_or_change_value(env, "PWD", ft_strdup(newpath));
		if (closedir(dir) == -1)
			return perror("mnishell closeder"), -3;
	}
	return (0);
}
