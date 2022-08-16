/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/08/16 05:47:56 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int	main(void) 
{
	t_vars	vars;

	while (1)
	{
		init(&vars);
	 	getdir(&vars.base_name);
		vars.cmd = readline(vars.base_name);
		if (vars.cmd == NULL)
		{
			free_all(&vars);
			return perror("EOF"), 1;
		}
		if (!ft_strcmp(vars.cmd, ""))
			continue;
		vars.tab_cmd = ft_split(vars.cmd, ' ');
		parse(vars.tab_cmd, &vars.node);
		calculate(vars.node);
		printf("%d\n", vars.node->data);
		free_all(&vars);
	}
	return 0;
}
