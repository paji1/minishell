/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 06:57:18 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/24 08:59:43 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute_builtins(t_node *node, t_env *env)
{
    char    **cmd;

    cmd = qto_tab(node, env);
    if (!ft_strcmp(node->token.token, "cd"))
        ft_cd(cmd, env);
    // if (!ft_strcmp(node->token.token, "echo"))
    //     ft_echo(cmd);
    // if (!ft_strcmp(node->token.token, "env"))
    //     ft_env(env);
    // if (!ft_strcmp(node->token.token, "pwd"))
    //     ft_pwd(env);
    free(cmd);
    return (0);   
}
