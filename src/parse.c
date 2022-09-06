/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:22:43 by akharraz          #+#    #+#             */
/*   Updated: 2022/09/06 22:10:10 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *lexer(char *buff, t_sub *sub)
{
    printf("%s\n", ft_substr(buff, sub->start, sub->end - sub->start));
    return NULL;
}

char    *handle_special(char *buff, t_sub *sub, int *i)
{
    if (is_special(buff) == 1)
    {
        printf("%s\n",ft_substr(buff, 0, 1));
        sub->start = *i + 1;
    }
    else if (is_special(buff) == 2)
    {
        printf("%s\n",ft_substr(buff, 0, 2));
        sub->start = *i + 2;
        *i += 1;
    }
    (void)sub;
    return NULL;
}

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
            lexer(vars->buff, &sub);
        handle_special(&vars->buff[i], &sub, &i); 
        start_token(vars->buff, i, &sub);
    }
    handle_last(vars->buff, i, &sub);
    return 0;
}