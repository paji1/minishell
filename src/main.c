/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/07 16:21:13 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int get_type(char *token);
int	main(int ac, char **av, char**env) 
{
	t_vars	vars;

	(void)ac;
	(void)av;
	while (1)
	{
		init(&vars, env);
	 	getdir(&vars.base_name);
		vars.buff = readline(vars.base_name);
		if (vars.buff == NULL)
			return free_all(&vars), printf("exit\n"), 0;
		if (vars.buff[0] && !parse(&vars))
		{
			free_all(&vars);
			continue;
		}
		exucute(vars.root, &vars);
		while (vars.pid_num >= 0)
		{
			wait();
			vars.pid_num--;
		}
		free_all(&vars);
	}
	return 0;
}
