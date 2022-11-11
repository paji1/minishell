/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 05:17:34 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/11 13:39:02 by tel-mouh         ###   ########.fr       */
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
		getcwd(oldpath, PATH_MAX);
		if (!ft_strcmp(oldpath, ""))
			add_or_change_value(env, "OLDPWD", ft_strdup(oldpath));
		if (chdir(cmd[1]) == -1)
			return closedir(dir), perror("mnishell"), -2;
		if (!getcwd(newpath, PATH_MAX))
			return closedir(dir), -4;
		add_or_change_value(env, "PWD", ft_strdup(newpath));
		if (closedir(dir) == -1)
			return perror("mnishell"), -3;
	}
	return (0);
}
