/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 06:57:18 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/16 09:20:47 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_get_backfd(t_node *node, int in, int out)
{
	close(node->file_out);
	node->file_out = dup(out);
	node->file_in = dup(in);
	close(out);
	close(in);
}

int execute_builtins(t_node *node, t_env *env)
{
	char			**cmd;
	int				out;
	int				in;

	cmd = qto_tab(node, env);
	out = dup(node->file_out);
	in = dup(node->file_in);
	if (handle_redirection(node, env))
		return free(cmd), ft_get_backfd(node, in, out), -1;
	if (!ft_strcmp(node->token.token, "cd"))
		ft_cd(cmd, env);
	else if (!ft_strcmp(node->token.token, "echo"))
		ft_echo(cmd);
	else if (!ft_strcmp(node->token.token, "env"))
		ft_env(env);
	else if (!ft_strcmp(node->token.token, "pwd"))
		ft_pwd(env);
	else if (!ft_strcmp(node->token.token, "unset"))
		ft_unset(cmd, env);
	else if (!ft_strcmp(node->token.token, "export"))
		ft_export(cmd, env);
	else if (!ft_strcmp(node->token.token, "exit"))
		ft_exit(cmd);
	ft_get_backfd(node, in, out);
	free(cmd);
	return (0);
}
