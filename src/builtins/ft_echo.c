/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 01:30:00 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/19 06:12:47 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_option(char *arg)
{
	int	i;

	i = 0;
	while (arg[++i])
	{
		if (arg[i] != 'n')
			return (FALSE);
	}
	if (!arg[1])
		return (FALSE);
	return (TRUE);
}

int	ft_echo(char **cmd)
{
	int	i;
	int	lock;

	lock = 0;
	i = 0;
	while (cmd[++i])
	{
		if (lock >= 0 && cmd[i][0] == '-' && check_option(cmd[i]) == TRUE)
		{
			lock = 1;
			continue ;
		}
		if (lock == 1)
			lock = -1;
		if (lock == 0)
			lock = -42;
		ft_putstr_fd(cmd[i], STDOUT_FILENO);
		if (cmd[i + 1])
			write(1, " ", 1);
	}
	if (lock != 1 && lock != -1)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
