/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:27:01 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/18 20:30:31 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_pranteses(t_node *new)
{
	static int	state;

	if (new == NULL)
	{
		if (!state)
			return (state = 0, 0);
		else
			return (state = 0, 1);
	}
	if (new->node_type != PR)
		return (0);
	if (!state && new->token.type == RP)
		return (1);
	if (new->token.type == LP)
		return (state++, 0);
	else if (new->token.type == RP)
		return (state--, 0);
	return (0);
}

int	handle_empty_cmd(t_node *new)
{
	static char	flag;

	if (!(*new->token.token))
		return (flag = 1, 1);
	if (flag == 0)
		return (0);
	if (new->token.type == ARG)
		return (flag = 0, 1);
	if (\
		new->token.type != FILED && \
		!(new->token.type >= REDIRECT_SO && new->token.type <= HERDOC))
		return (flag = 0, 0);
	return (0);
}
