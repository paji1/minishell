/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 05:17:34 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/20 23:00:20 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	go_to_home(t_env *env, char *str)
{
	char		**path;
	t_env_node	*node;

	path = NULL;
	node = env->head;
	if (!str)
		str = "HOME";
	else
		str = "OLDPWD";
	while (node)
	{
		if (!ft_strncmp(node->key, str, ft_strlen(str)))
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
	return (print_to_error(str, " not set", 1));
}

static int	curent_parentdir_error(t_env *env, char *cmd, DIR *dir)
{
	char	*old;
	char	*point_path;
	char	oldpath[PATH_MAX];

	if (chdir(cmd) == -1)
		return (closedir(dir), perror("mnishell chdir"), 1);
	if (getcwd(oldpath, PATH_MAX))
		return (closedir(dir), 0);
	old = get_value(env, "OLDPWD");
	if (!old)
		return (-1);
	point_path = ft_strjoin("/", cmd);
	if (!point_path)
		return (free(old), closedir(dir), -1);
	add_or_change_value(env, ft_strdup("PWD"), ft_strjoin(old, point_path));
	free(point_path);
	free(old);
	ft_putstr_fd("cd: error retrieving current directory: ", 2);
	ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
	ft_putendl_fd("No such file or directory", 2);
	closedir(dir);
	return (1);
}

static int	change_to_new_dir(DIR *dir, t_env *env, char **cmd, char *newpath)
{
	if (chdir(cmd[1]) == -1)
		return (closedir(dir), perror("mnishell chdir"), 1);
	if (!getcwd(newpath, PATH_MAX))
		return (closedir(dir), 1);
	add_or_change_value(env, ft_strdup("PWD"), ft_strdup(newpath));
	if (closedir(dir) == -1)
		return (perror("mnishell closeder"), 1);
	return (0);
}

int	ft_cd(char **cmd, t_env *env)
{
	char	newpath[PATH_MAX];
	char	oldpath[PATH_MAX];
	DIR		*dir;

	ft_bzero(newpath, PATH_MAX);
	ft_bzero(oldpath, PATH_MAX);
	if (!cmd[1] || !ft_strcmp(cmd[1], "-"))
		return (go_to_home(env, cmd[1]));
	if (cmd[1])
	{
		dir = opendir(cmd[1]);
		if (dir == NULL)
			return (perror("mnishell"), 1);
		if (!getcwd(oldpath, PATH_MAX))
		{
			if (!ft_strcmp("..", cmd[1]))
				return (curent_parentdir_error(env, cmd[1], dir));
			return (perror("minishell"), closedir(dir), 1);
		}
		add_or_change_value(env, ft_strdup("OLDPWD"), ft_strdup(oldpath));
		if (change_to_new_dir(dir, env, cmd, newpath))
			return (1);
	}
	return (0);
}
