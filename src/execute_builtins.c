/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 06:57:18 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/03 22:16:04 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute_builtins(t_node *node, t_env *env)
{
	char    **cmd;
	int out;
	
	cmd = qto_tab(node, env);
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
	free(cmd);
	return (0);
}
