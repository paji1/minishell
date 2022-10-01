/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:22:43 by akharraz          #+#    #+#             */
/*   Updated: 2022/09/27 07:08:43 by tel-mouh         ###   ########.fr       */
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
    if (!handle_last(vars, i, &sub))
        return 0;
    if (quote.in_quote == TRUE)
        return printf("Minishell: syntax error near unexpected quote \n"), 0;
    get_type(NULL);
    if (!accepted(NULL))
        return printf("Minishell: syntax error near unexpected token\n"), 0;
    print_tree(vars->root, vars);
    return 0;
}