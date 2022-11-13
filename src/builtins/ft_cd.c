/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 05:17:34 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/13 00:12:17 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/errno.h>

int	ft_cd(char  **cmd, t_env *env)
{
	char newpath[PATH_MAX];
	char oldpath[PATH_MAX];
	DIR *dir;

	ft_bzero(newpath, PATH_MAX);
	ft_bzero(oldpath, PATH_MAX);
	
	if (cmd[1])
	{
		dir = opendir(cmd[1]);
		if (dir == NULL)
			return (perror("mnishell"), -1);
		if (readdir(dir) == NULL)
			return (perror("reddir"), -1);
		getcwd(oldpath, PATH_MAX);
		if (!ft_strcmp(oldpath, ""))
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
