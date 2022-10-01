/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:13:18 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/01 12:45:18 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_tree(t_node *root)
{
    if (!root)
        return ;
    free_tree(root->left);
    free_tree(root->right);
    if (root->token.args_q)
        free_queue(root->token.args_q);
    if (root->token.redir)
        free_queue(root->token.redir);
    free(root->token.token);
    free(root);
}

void    free_all(t_vars *vars)
{
    if (vars->base_name)
        free(vars->base_name);
    if (vars->buff)
        free(vars->buff);
    free_stack(vars->roots);
    free_tree(vars->root);
}