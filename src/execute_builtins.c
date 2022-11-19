/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 06:57:18 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/18 23:08:58 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_backfd(t_node *node, int in, int out)
{
	close(node->file_out);
	node->file_out = dup(out);
	node->file_in = dup(in);
	close(out);
	close(in);
}

static int	execute_the_cmd(t_node *node, t_env *env, char **cmd)
{
	if (!ft_strcmp(node->token.token, "cd"))
		node->token.exit_status = ft_cd(cmd, env);
	else if (!ft_strcmp(node->token.token, "echo"))
		node->token.exit_status = ft_echo(cmd);
	else if (!ft_strcmp(node->token.token, "env"))
		node->token.exit_status = ft_env(env, cmd);
	else if (!ft_strcmp(node->token.token, "pwd"))
		node->token.exit_status = ft_pwd(env);
	else if (!ft_strcmp(node->token.token, "unset"))
		node->token.exit_status = ft_unset(cmd, env);
	else if (!ft_strcmp(node->token.token, "export"))
		node->token.exit_status = ft_export(cmd, env);
	else if (!ft_strcmp(node->token.token, "exit"))
		node->token.exit_status = ft_exit(cmd);
	return (0);
}

int	execute_builtins(t_node *node, t_env *env)
{
	char			**cmd;
	int				out;
	int				in;

	cmd = qto_tab(node, env);
	out = dup(node->file_out);
	in = dup(node->file_in);
	if (handle_redirection(node, env))
		return (free(cmd), ft_get_backfd(node, in, out), -1);
	execute_the_cmd(node, env, cmd);
	ft_get_backfd(node, in, out);
	free(cmd);
	return (0);
}
