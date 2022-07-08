/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:55:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/07 04:50:24 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H



# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "types.h"
# include "stack.h"

void	insert(t_node **node, t_node *new);
int		contain(t_node **node, int data);
t_node	*new_node(int data, int type);
void	free_tree(t_node **node);
// --------------depth_first_values-----------
void	preorder(t_node *node);
void	iter_print(t_node *node);
// --------------breadth_first_values-----------
void brefirstrev(t_node *node);
// ---------------------------------------------







#endif