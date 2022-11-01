/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 05:17:34 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/01 04:14:08 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

int	ft_cd(char  **cmd, t_env *env)
{
	char newpath[PATH_MAX];
	char oldpath[PATH_MAX];
	DIR *dir;

	if (cmd[1])
	{
		dir = opendir(cmd[1]);
		if (dir == NULL)
			return (0);
		if (!getcwd(oldpath, PATH_MAX))
			return -4;
		add_or_change_value(env, "OLDPWD", ft_strdup(oldpath));
		if (chdir(cmd[1]) == -1)
			return -2;
		if (!getcwd(newpath, PATH_MAX))
			return -4;
		add_or_change_value(env, "PWD", ft_strdup(newpath));
		if (closedir(dir) == -1)
			return printf("closedir faild\n"), -3;
	}
	return (0);
}
