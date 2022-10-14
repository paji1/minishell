/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/14 05:37:27 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env) 
{
	t_vars	vars;

	(void)ac, (void)av;
	while (1)
	{
		init(&vars, env);
	 	getdir(&vars.base_name);
		vars.buff = readline(vars.base_name);
		if (vars.buff == NULL)
			return free_all(&vars), printf("exit\n"), 0;
		add_history(vars.buff);
		if (vars.buff[0] && !parse(&vars))
		{
			free_all(&vars);
			continue;
		}
		exucute(vars.root, &vars);
		while (vars.pid_num-- >= 0)
			wait(0);
		// printf("%d", WEXITSTATUS(vars.root->token.exit_status));
		free_all(&vars);
	}
	return 0;
}
