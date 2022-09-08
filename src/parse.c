/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:22:43 by akharraz          #+#    #+#             */
/*   Updated: 2022/09/08 18:59:26 by tel-mouh         ###   ########.fr       */
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
            handle_token(lexer(vars->buff   , &sub), vars);
        handle_token(handle_special(&vars->buff[i], &sub, &i), vars);
        start_token(vars->buff, i, &sub);
    }
    handle_last(vars, i, &sub);
    print_tree(vars->root);
    return 0;
}