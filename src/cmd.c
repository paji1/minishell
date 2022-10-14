// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   cmd.c                                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/09/25 00:05:03 by tel-mouh          #+#    #+#             */
// /*   Updated: 2022/10/05 17:24:16 by tel-mouh         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minishell.h"

char **qto_tab(t_node *node)
{
	char	**tab;
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
		tab[i] = q_n_get(node->token.args_q)->data->token.token;
	}
	return tab[size - 1] = NULL, tab;
}
