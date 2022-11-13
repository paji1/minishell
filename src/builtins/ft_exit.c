/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:13:23 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/13 12:50:39 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void exit_errors(char *str, int mode)
{
	ft_putendl_fd("minishell: exit: ",2);
	ft_putendl_fd(str ,2);
	if (mode == 0)
		ft_putendl_fd(": numeric argument required" ,2);
	if (mode == 1)
		ft_putendl_fd(": too many arguments" ,2);
}

static int	is_numeric(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
	}
	return (0);
}

void	ft_exit(char **cmd)
{
	unsigned char	stat;

	stat = 0;
	ft_putendl_fd("exit", 1);
	if (cmd[1])
	{
		if (is_numeric(cmd[1]) == -1)
		{
			exit_errors(cmd[1], 0);
			exit(-1);
		}
		if (cmd[2])
		{
			exit_errors(cmd[1], 1);
			return ;
		}
		stat = (unsigned char)ft_atoi(cmd[1]);
	}
	exit(stat);
}