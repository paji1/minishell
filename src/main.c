/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/14 20:36:08 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(int ac, char **av, char **env) 
{
	t_vars	vars;

	(void)ac, (void)av;
	if (init_env(&vars, env))
		return  (2);
	handle_history(&vars);
	while (1)
	{
		hide_ctrl_c();
		if (init(&vars, env))
			return free_env(vars.env), 1;
	 	getdir(&vars.base_name);
		vars.buff = readline(vars.base_name);
		add_history_write(&vars);
		if (vars.buff == NULL)
			return free_env(vars.env), free_all(&vars), ft_putendl_fd("exit", 2), 0;
		if (vars.buff[0] && !parse(&vars))
		{
			free_all(&vars);
			continue ;
		}
		exucute(vars.root, &vars);
		while (vars.pid_num-- >= 0)
					wait(0);
		free_all(&vars);
	}
	return 0;
}
