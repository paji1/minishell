/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:05:03 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/14 04:01:24 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char **qto_tab(t_node *node, t_env *env)
{
	char	**tab;
	t_nodeq *temp;
	int		size;
	int		i;

	i = 0;
	if (!node)
		return NULL;
	if (node->token.args_q)
		size = node->token.args_q->size + 2;
	else
		size = 2;
	tab = malloc(sizeof(tab) * size);
	if (!tab)
		return NULL;
	tab[0] = node->token.token;
	if (!node->token.args_q)
		return tab[1] = NULL, tab;
	while (++i < size - 1)
	{
		temp = q_n_get(node->token.args_q);
		expand_str(&temp->data->token.token, env);
		tab[i] = temp->data->token.token;
	}
	return tab[size - 1] = NULL, tab;
}
