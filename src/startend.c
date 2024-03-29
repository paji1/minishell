/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:41:02 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/17 13:37:27 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_spacial_space(char *buff, int i)
{
	if (i >= 0)
		return (is_special(&buff[i]) || is_space(buff[i]));
	return (0);
}
/**
 * @brief check the end of tokens
 * 
 * @param buff return of readline 
 * @param i count inside parse function
 * @param sub where is start and end of token
 * @return int end or not
 */

int	end_token(char *buff, int i, t_sub *sub)
{
	if (is_spacial_space(buff, i - 1) && is_spacial_space(buff, i))
		return (0);
	if (is_space(buff[i]) && buff[i - 1] != '&' && buff[i - 1] != '|')
		return (sub->end = i, 1);
	else if (is_special(&buff[i]))
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
void	start_token(char *buff, int i, t_sub *sub)
{
	if (is_space(buff[i]))
		sub->start = i + 1;
}

static int	check_open_quote(int in_quote)
{
	if (in_quote != TRUE)
		return (0);
	accepted(NULL);
	get_type(NULL);
	ft_putendl_fd("minishell: syntax error near unexpected quote", 2);
	return (1);
}

/**
 * @brief whene the parse loop exit white quote at end
 * 
 * @param buff return of readline
 * @param i count inside parse function
 * @param sub where is start and end of token
 */
int	handle_last(t_vars *vars, int i, t_sub *sub, t_quote *quote)
{
	if (end_token(vars->buff, i, sub) && ft_strchr("\"'", vars->buff[i - 1]))
		if (!handle_token(lexer(vars->buff, sub), vars))
			return (0);
	free_pr(NULL);
	if (check_open_quote(quote->in_quote))
		return (0);
	get_type(NULL);
	if (!accepted(NULL))
		return (ft_putendl_fd(\
			"minishell: syntax error near unexpected token", 2), 0);
	return (1);
}
