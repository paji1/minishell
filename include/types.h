/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:01:38 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/08 20:13:33 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define TOKEN 1
# define NUM 0


enum TOKENS
{
	division = '/' ,multiply = '*' ,addition = '+',subtraction = '-'
};

typedef struct s_node
{
	int data;
	int type;
	struct s_node *right;
	struct s_node *left;	
}t_node;

typedef struct s_vars
{
	char *cmd;
	char **tab_cmd;
	t_node *node;
} t_vars;


#endif