/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:37:20 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/05 00:38:04 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int contain(t_node **node, int data)
{
	if ((*node) == NULL)
		return 0;
	if (data == (*node)->data)
		return 1;
	if (data < (*node)->data)
		return contain(&(*node)->left, data);
	else
		return contain(&(*node)->right, data);
}
