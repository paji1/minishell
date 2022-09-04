/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:22:43 by akharraz          #+#    #+#             */
/*   Updated: 2022/09/04 04:13:05 by akharraz         ###   ########.fr       */
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

int check_end(char *buff, t_quote *quote, int i)
{
    if ((quote->in_quote == TRUE && quote->quote == buff[i]))
        quote->in_quote = FALSE; 

    if (quote->in_quote == FALSE && (buff[i + 1] == ' ' || !buff[i + 1]))
        return quote->in_quote = FALSE, 1;
    if (quote->in_quote == FALSE && (buff[i + 1] == '|' || !buff[i + 1]))
        return quote->in_quote = FALSE, 1;
    return 0;
}

int parse(t_vars *vars)
{
    int i;
    t_sub sub;
    t_quote quote;

    i = -1;
    ft_bzero((void *)&sub, sizeof(t_sub));
    ft_bzero((void *)&quote, sizeof(t_quote));
    while (vars->buff[++i])
    {
        if (vars->buff[i] == ' ' && quote.in_quote == FALSE)
            continue;
        if (!sub.end)
        {
            sub.end = 1;
            sub.start = i;
        }
        if (ft_strchr("\"'", vars->buff[i]) && quote.in_quote == FALSE)
        {
            quote.quote = vars->buff[i];
            quote.in_quote = TRUE;
            continue ;
        }
        if (check_end(vars->buff, &quote, i))
        {
            printf("%s\n", ft_substr(vars->buff, sub.start, i - sub.start + 1));
            sub.end = 0;
        }
    }
    return 0;
}