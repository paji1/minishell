/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:56:34 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/21 03:08:28 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_cmd(t_node *node, t_env *env)
{
	char	**cmd;
	char	*path;

	if (node->token.type != CMD)
		return (0);
	path = NULL;
	free_and_allocate(env);
	hide_ctrl_c();
	cmd = qto_tab(node, env);
	if (!cmd)
		return (-1);
	expand_str(&node->token.token, env);
	if (ft_isbuiltin(cmd[0]))
		return (execute_builtins(node, env), exit(node->token.exit_status), 0);
	if (check_cmd(node, env, &path) < 0 \
	|| execve(path, cmd, env->env_tab) == -1)
		return (free(cmd), free(path), exit(127), -3);
	if (path)
		free(path);
	if (cmd)
		free(cmd);
	return (0);
}

static void	cmd_first(t_node *node)
{
	close_before(node->file_in);
	dup2(node->file_out, 1);
	if (node->file_out != STDOUT_FILENO)
		close(node->file_out);
}

static void	cmd_not_first(t_node *node)
{
	dup2(node->file_in, 0);
	dup2(node->file_out, 1);
	close_before(node->file_out);
}

int	fork_cmd(t_node *node, t_env *env)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid)
		return (ignore_signal(), node->token.pid_child = pid, pid);
	remove_signal();
	if (handle_redirection(node, env) == -1)
		exit(1);
	if (is_first(node))
		cmd_first(node);
	if (!is_first(node))
		cmd_not_first(node);
	if (execute_cmd(node, env) < 0)
		return (-1);
	return (remove_signal(), 0);
}
