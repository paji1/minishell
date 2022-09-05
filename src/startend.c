/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:41:02 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/05 19:05:44 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief check the end of tokens
 * 
 * @param buff 
 * @param i 
 * @param sub 
 * @return int 
 */
int end_token(char *buff, int i, t_sub *sub)
{
    if (is_space(buff[i]) && !is_space(buff[i - 1]))
        return (sub->end = i, 1);
	else if(is_special(&buff[i]) && !is_special(&buff[i - 1]))
		return (sub->end = i, 1);
    else if (!buff[i + 1])
        return (sub->end = i + 1, 1);
    return (0);
}

void start_token(char *buff, int i, t_sub *sub)
{
    if (is_space(buff[i]))
        sub->start = i + 1;
}

void handle_last(char *buff, int i, t_sub *sub)
{
    if (end_token(buff, i, sub) && ft_strchr("\"'", buff[i - 1]))
        lexer(buff, sub);
}