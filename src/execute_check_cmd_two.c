/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_check_cmd_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:50:28 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/19 06:24:02 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_if_path(char *cmd)
{
	int	i;

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
		return (print_to_error(cmd, " No such file or directory", -1));
	if (access(cmd, R_OK) == -1)
		return (print_to_error(NULL, "Permission denied", -2));
	if (access(cmd, X_OK) == -1)
		return (print_to_error(NULL, "Permission denied", -3));
	return (1);
}

int	check_if_dir(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir)
		return (print_to_error(path, ": is a directory", -1));
	return (1);
}

void	print_cnf(char *key)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(key, 2);
	ft_putendl_fd(": command not found", 2);
}
