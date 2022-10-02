/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/02 07:33:47 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int get_type(char *token);
int	main(void) 
{
	t_vars	vars;

	while (1)
	{
		init(&vars);
	 	getdir(&vars.base_name);
		vars.buff = readline(vars.base_name);
		if (vars.buff == NULL)
			return free_all(&vars), printf("exit\n"), 0;
		if (vars.buff[0])
			parse(&vars);
		exucute(vars.root, &vars);
		free_all(&vars);
	}
	return 0;
}
