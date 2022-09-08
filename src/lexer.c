/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 23:21:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/08 20:21:56 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *lexer(char *buff, t_sub *sub)
{
    return (ft_substr(buff, sub->start, sub->end - sub->start));
}

char    *handle_special(char *buff, t_sub *sub, int *i)
{
    if (is_special(buff) == 1)
        return (sub->start = *i + 1, ft_substr(buff, 0, 1));
    else if (is_special(buff) == 2)
        return (sub->start = *i + 2, *i += 1, ft_substr(buff, 0, 2));
    return NULL;
}