/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:41:02 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/05 19:13:58 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief check the end of tokens
 * 
 * @param buff return of readline 
 * @param i count inside parse function
 * @param sub where is start and end of token
 * @return int end or not
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

/**
 * @brief intialize the sub start
 * 
 * @param buff return of readline
 * @param i count inside parse function
 * @param sub where is start and end of token
 */
void start_token(char *buff, int i, t_sub *sub)
{
    if (is_space(buff[i]))
        sub->start = i + 1;
}

/**
 * @brief whene the parse loop exit white quote at end
 * 
 * @param buff return of readline
 * @param i count inside parse function
 * @param sub where is start and end of token
 */
void handle_last(char *buff, int i, t_sub *sub)
{
    if (end_token(buff, i, sub) && ft_strchr("\"'", buff[i - 1]))
        lexer(buff, sub);
}