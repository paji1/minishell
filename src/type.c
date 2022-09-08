/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:22:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/08 17:29:05 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_type(char *token)
{
	static int last_token;

	if (!ft_strcmp(token , "||"))
		return last_token = OR , OR;
	else if (!ft_strcmp(token , "&&"))
		return last_token = AND , AND;
	else if (!ft_strcmp(token , "|"))
		return last_token = PIP , PIP;
	else if (!ft_strcmp(token, ">"))
		return last_token = REDIRECT_SO , REDIRECT_SO;
	else if (!ft_strcmp(token, "<"))
		return last_token = REDIRECT_SI , REDIRECT_SI;
	else if (!ft_strcmp(token, ">>"))
		return last_token = APPEND , APPEND;
	else if (!ft_strcmp(token, "<<"))
		return last_token = HERDOC , HERDOC;
	else
	{
		if (!last_token || last_token == PIP || last_token == AND || last_token == OR )
			return last_token = CMD, CMD;
		else if (last_token == REDIRECT_SO || last_token == REDIRECT_SI || last_token == APPEND || last_token == HERDOC)
			return last_token = FILED , FILED;
		else if (last_token == CMD && token[0] == '-')
			return last_token = OPTIONS , OPTIONS;
		else
			return last_token = ARG , ARG;
	}
	// return -1;
}

int block_op(char *token)
{
	int type;

	type = get_type(token);
	if (type == CMD || type == FILED || type == ARG|| type == OPTIONS )
		return BLOCK;
	else
		return OP;
}