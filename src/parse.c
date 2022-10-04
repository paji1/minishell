/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:22:43 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/04 01:20:44 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int parse(t_vars *vars)
{
    int     i;
    t_sub   sub;
    t_quote quote;

    i = -1;
    ft_bzero((void *)&sub, sizeof(t_sub));
    ft_bzero((void *)&quote, sizeof(t_quote));
    while (vars->buff[++i])
    {
        if (quote_handle(&quote, i, vars->buff))
            continue;
        if (end_token(vars->buff, i, &sub))
            if (!handle_token(lexer(vars->buff   , &sub), vars))
                return 0;
        if (!handle_token(handle_special(&vars->buff[i], &sub, &i), vars))
                return 0;
        start_token(vars->buff, i, &sub);
    }
    if (!handle_last(vars, i, &sub, &quote))
        return 0;
    // print_tree(vars->root, vars);
    return 0;
}