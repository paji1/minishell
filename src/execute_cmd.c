/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:56:34 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/14 23:05:33 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute_cmd(t_node *node, t_env *env)
{
	char	 **cmd;
	char	 *path;
	int		error;

	if (node->token.type != CMD)
		return 0;
	path = NULL;
	free_and_allocate(env);
	hide_ctrl_c();
	cmd = qto_tab(node, env);
	if(!cmd)
		return -1;
	expand_str(&node->token.token, env);
	if (ft_isbuiltin(cmd[0]))
		return (execute_builtins(node, env), exit(0), 0);
	if (check_cmd(node, env, &path) < 0 || execve(path, cmd, env->env_tab) == -1)
		return free(cmd), free(path), exit(1), -3;
	if (path)
		free(path);
	if (cmd)
		free(cmd);
	return 0;
}

int fork_cmd(t_node *node, t_env *env)
{
	int pid;

	ignore_signal();
	pid = fork();
	if (pid == -1)
		return -1;
	if (pid)
		return node->token.pid_child = pid , pid;
	if (handle_redirection(node) == -1)
		exit(1);
	if (is_first(node))
	{
		close_before(node->file_in);
		dup2(node->file_out, 1);
		if (node->file_out != STDOUT_FILENO)
			close(node->file_out);
	}
	if (!is_first(node))
	{
		dup2(node->file_in, 0);
		dup2(node->file_out, 1);
		close_before(node->file_out);
	}
	if (execute_cmd(node, env) < 0)
		return -1;
	handle_signal();
	return 0;
}
