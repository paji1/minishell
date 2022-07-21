/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/21 00:56:03 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


//                      +
//                 /        \                         /
//               *           +
//              /  \        /  \                      /
//            8    3       *   1
//                       /  \                         /
//                      -4  8

// (8 * 3) + (((-4) * 8) + 1)

static int check_types(char *s)
{
	char *op;

	op = "-+*/";
	while(*op)
	{
		if (ft_strchr(s, *op))
			return (TOKEN);
		op++;
	}
	return (NUM);
}

void	nested(t_node **node, int token, int right)
{
	t_node *temp;

	temp = (*node)->right;
	(*node)->right = new_node(token, TOKEN);
	(*node)->right->left = temp;
	(*node)->right->right = new_node(right , NUM);
}



void parse(char **s, t_node **node)
{
	int 	i;
	t_node	*temp;

	i = -1;
	while (s[++i])
	{
		if (check_types(s[i]) == TOKEN)
		{
			if (s[i][0] == multiply)
			{
				nested(node, multiply, atoi(s[++i]));
			}
			else if (s[i][0] == addition)
			{
				temp = new_node(addition , TOKEN);
				temp->right = new_node(ft_atoi(s[++i]) , NUM);
				temp->left = (*node);
				*node = temp;
			}
		}
		else
		{
			(*node) = new_node(s[i + 1][0], TOKEN);
			(*node)->left = new_node(ft_atoi(s[i]), NUM);
			(*node)->right = new_node(ft_atoi(s[i + 2]), NUM);
			i += 2;
		}
	}
}

int main(int ac, char **args) 
{
	t_vars vars;

	(void)ac;
	vars.cmd = "8 * 3 + -4 * 8 + 1";
	vars.tab_cmd = args;
	vars.node = NULL;
	parse(vars.tab_cmd , &vars.node);
	
	preorder(vars.node);
	printf("%d\n", vars.node->data);
	free_tree(&vars.node);	
	// 	printf("%d\n", contain(&node, i));
	return 0;
}
