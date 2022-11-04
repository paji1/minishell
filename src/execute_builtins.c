/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 06:57:18 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/04 09:45:41 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_redirection
{
	int	out;
	int	in;
}	t_redirection;

static int pass_fd(t_node *node, t_redirection *red)
{
	;
	return (0);
}

static int repass_fd(t_node *node, t_redirection *red)
{
	return (0);
}

int execute_builtins(t_node *node, t_env *env)
{
	char			**cmd;
	t_redirection	*red;
	
	red = malloc(sizeof(t_redirection));
	cmd = qto_tab(node, env);
	// if (!node->file_in && node->file_out == 1)
	// 	pass_fd(node, red);
	handle_redirection(node);
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
	// repass_fd(node, red);
	free(cmd);
	return (0);
}
