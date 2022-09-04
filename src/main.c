/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/04 00:29:28 by akharraz         ###   ########.fr       */
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
		vars.buff = readline(vars.base_name);
		if (vars.buff == NULL)
			return free(vars.base_name), printf("exit\n"), 1;
		parse(&vars);
		free_all(&vars);
	}
	return 0;
}
