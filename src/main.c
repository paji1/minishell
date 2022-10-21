/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/21 06:58:41 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env) 
{
	t_vars	vars;

	(void)ac, (void)av;
	if (init_env(&vars, env))
		return  (2);
	while (1)
	{
		if (init(&vars, env))
			return 1;
	 	getdir(&vars.base_name);
		vars.buff = readline(vars.base_name);
		if (vars.buff == NULL)
			return free_all(&vars), printf("exit\n"), 0;
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




// int	main(int ac, char **av, char **env) 
// {

// 	(void)ac, (void)av;
// 	t_vars vars;
	

// 	(void)ac, (void)av;
// 	if (init_env(&vars, env))
// 		return  (2);
// 	// char *key = ft_strdup("USER");
// 	// char *value = ft_strdup("taha");
// 	char *str = ft_strdup("hello'\"$hello\"'$hid");
// 	expand_str(&str, vars.env);
// 	printf("%s\n", str);
// 	free(str);
// 	free_env(vars.env);
// 	// free(value);
// }