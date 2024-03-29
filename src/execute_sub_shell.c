/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sub_shell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:09:31 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/21 08:46:35 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_sub(t_node *node, t_vars *vars)
{
	int	pid;

	if (!is_sub(node) && node->is_sub == 0)
		return (0);
	if (!node->is_sub)
		node->node_type = OP;
	node->is_sub = 0;
	pid = fork();
	if (!pid)
	{
		handle_redirection(node, vars->env);
		if (!node)
			return (0);
		dup2(node->file_in, 0);
		dup2(node->file_out, 1);
		vars->pid_num = 0;
		exucute(node, vars);
		while (vars->pid_num-- > 0)
			wait(0);
		exit(WEXITSTATUS(node->token.exit_status));
	}
	waitpid(pid, &node->token.exit_status, 0);
	if (node->node_type == OP)
		node->is_sub = 1;
	return (close_in_parent(node), 1);
}
