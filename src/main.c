/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/15 18:49:02 by tel-mouh         ###   ########.fr       */
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
			return free(vars.base_name), printf("exit\n"), 1;
		if (vars.buff[0])
			parse(&vars);
		free_all(&vars);
	}
	return 0;
}
