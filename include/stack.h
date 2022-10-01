#ifndef STACK_H
# define STACK_H

typedef struct s_node t_node;
/**
 * @file types.h
 * @brief Contains the types used in the project.
 */

/**
 * @brief node structure
 * @details Contains the data of node
 * @param data The data of the node.
 * @param next The next node.
 * @param prev The previous node.
 */
typedef struct s_snode
{
	t_node			*root;
	struct s_snode	*next;
	struct s_snode	*prev;
}t_snode;

/**
 * @brief queeue structure
 * @note pointed to head and tail. of the stack.
 * @param head pointer to the head of the stack
 * @param tail pointer to the tail of the stack
 * @param size size of the stack
 *
 */
typedef struct s_stack
{
	struct s_snode	*head;
	struct s_snode	*tail;
	int				size;
}t_stack;

t_snode	*new_snode(t_node *data);
t_stack	*new_stack();
void	push(t_stack *stack, t_snode *new);
t_snode	*sget(t_stack *stack);
t_snode	*pop(t_stack *stack);
void	free_stack(t_stack *stack);


#endif