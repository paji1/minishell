/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:01:38 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/07 05:26:42 by tel-mouh         ###   ########.fr       */
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


#endif