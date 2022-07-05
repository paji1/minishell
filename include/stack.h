/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:03:10 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/04 20:43:40 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
typedef struct s_node t_node;
typedef struct s_stack
{
	t_node			*node;
	struct s_stack	*next;
}t_stack;

void	push(t_stack **stack, t_stack *new);
t_node *pop(t_stack **stack);
t_stack *new_element(t_node *data);
void	free_stack(t_stack **stack);


#endif