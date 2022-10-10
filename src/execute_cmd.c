/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:18:50 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/09 16:40:01 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute_cmd(t_node *node, char **env)
{
	char **cmd;
	char *path;
	int		error;

	if (node->token.type != CMD)
		return 0;
	cmd = qto_tab(node);
	if(!cmd)
		return -1;
	error = check_cmd(node, env, &path);
	if (error == 3)
		return perror("function Not found"), -2;
	if (error == 0)
		return perror("permission dnied"), -4;
	// ft_putstr_fd(node->token.token, 2);
	// ft_putstr_fd("\n", 2);
	if (execve(path, cmd, env) == -1)
		return -3;
	return 0;
}

int fork_cmd(t_node *node, char **env)
{
	int pid;

	pid = fork();
	if (pid == -1)
		return -1;
	if (pid)
		return node->token.pid_child = pid , pid;
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
	return 0;
}
