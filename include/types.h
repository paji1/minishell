/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:01:38 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/05 18:18:13 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H


# define FALSE 0
# define TRUE 1


# define OR "||"
# define AND "&&"
# define PIP "|"
# define REDIRECT_SO ">"
# define REDIRECT_SI "<"
# define APPEND ">>"
# define HERDOC "<<"

typedef struct s_node
{
	int data;
	int type;
	struct s_node *right;
	struct s_node *left;
}t_node;

typedef struct s_vars
{
	char	*buff;
	char	*token;
	t_node	*node;
	char	*base_name;
} t_vars;

typedef struct s_token
{
	char *cmd;
	int  quotes_tab[2];
	t_queue	*options_q;
	t_queue	*args_q;
}t_tokens;

typedef struct s_quote
{
	char	quote;
	int		in_quote;
}t_quote;

typedef struct s_sub
{
    int start;
    int end;
}t_sub;

#endif