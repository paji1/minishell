/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/21 03:24:39 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

void	exit_status(t_vars *vars)
{
	if (vars->root->node_type != BLOCK)
		return (g_exit_status = \
				WEXITSTATUS(vars->root->token.exit_status), (void)0);
	if (ft_isbuiltin(vars->root->token.token))
		return (g_exit_status = vars->root->token.exit_status, (void)0);
	g_exit_status = WEXITSTATUS(vars->exit_status);
	if (WIFSIGNALED(vars->exit_status))
		g_exit_status = WTERMSIG(vars->exit_status) + 128;
}

void	expand_before_parse(char **str, t_env *env)
{
	expand_str_before(str, env);
	expand_wildcard(str);
}

int	is_empty(char *str)
{
	while (*str)
	{
		if (!is_space(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	half_minishell(t_vars *vars)
{
	hide_ctrl_c();
	if (init(vars))
		return (free_env(vars->env), 1);
	getdir(&vars->base_name);
	vars->buff = readline(vars->base_name);
	if (vars->buff == NULL)
		return (free_env(vars->env), free_all(vars), \
			ft_putendl_fd("\033[1A\033[18Cexit", 1), vars->return_nb = 1, 1);
	add_history_write(vars);
	expand_before_parse(&vars->buff, vars->env);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_vars	vars;

	(void)ac, (void)av;
	if (init_env(&vars, env))
		return (2);
	handle_history(&vars);
	while (1)
	{
		if (half_minishell(&vars))
			return (vars.return_nb);
		if (is_empty(vars.buff) || !parse(&vars))
		{
			free_all(&vars);
			g_exit_status = 258;
			continue ;
		}
		exucute(vars.root, &vars);
		while (vars.pid_num-- >= 0)
			wait(&vars.exit_status);
		exit_status(&vars);
		free_all(&vars);
	}
	return (0);
}
