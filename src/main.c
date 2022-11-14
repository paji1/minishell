/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/14 07:12:45 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigaction_hand(int sig, siginfo_t *info, void *data)
{
	
	printf("\n"); // Move to a new line
    rl_on_new_line(); // Regenerate the prompt on a newline
    rl_replace_line("", 0); // Clear the previous text
    rl_redisplay();
}

int	main(int ac, char **av, char **env) 
{
	t_vars	vars;

	(void)ac, (void)av;
	vars.act.sa_flags = SA_SIGINFO;
	vars.act.sa_sigaction = &sigaction_hand;
	sigaction(SIGINT, &vars.act, NULL);
	hide_ctrl_c();
	if (init_env(&vars, env))
		return  (2);
	while (1)
	{
		if (init(&vars, env))
			return free_env(vars.env), 1;
	 	getdir(&vars.base_name);
		vars.buff = readline(vars.base_name);
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
		hide_ctrl_c();
		free_all(&vars);
	}
	return 0;
}
