/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:22:43 by akharraz          #+#    #+#             */
/*   Updated: 2022/09/04 20:51:04 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_sub
{
    int start;
    int end;
}t_sub;
#define FALSE 0
#define TRUE 1
// "|&><()*"



// char    *lexer()
// {
    
// }

int quote_handle(t_quote *quote, int i, char *buff)
{
    if (!ft_strchr("\"'", buff[i]) && quote->in_quote == FALSE)
        return  (0);
    if (!ft_strchr("\"'", buff[i]) && quote->in_quote == TRUE)
        return (1);
    if (quote->quote == buff[i] && quote->in_quote == TRUE)
        return quote->in_quote = FALSE , 1;
    if (ft_strchr("\"'", buff[i]) && quote->in_quote == FALSE)
        return quote->in_quote = TRUE, quote->quote =  buff[i] , 1;
    return 0;
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
        // if (end_token(&token, i, &sub))
        //     lexer(vars->buff, sub);
        printf("%c %d\n", vars->buff[i], i);
    }
    printf("%s\n", ft_substr(vars->buff, sub.start, i - sub.start + 1));
    return 0;
}