/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:01:38 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/20 07:40:23 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H


# define FALSE 0
# define TRUE 1
# define FILED 22
# define BLOCK 21
# define SPECIAL 5
# define OP 26


typedef enum e_etokens
{
	AND = 12,
	OR,
	PIP,
	REDIRECT_SO,
	REDIRECT_SI,
	APPEND,
	HERDOC,
	CMD,
	ARG,
	OPTIONS
}t_etoken;

typedef struct s_token
{
	char	*token;
	int		type;
	int	 	exit_status;
	t_queue	*args_q;
	t_queue	*redir;
}t_token;

typedef struct s_node
{
	t_token 		token;
	int				node_type;
	struct s_node	*right;
	struct s_node	*left;
}t_node;

typedef struct s_vars
{
	char	*buff;
	t_node	*root;
	char	*base_name;
	char	**op_tab;
} t_vars;


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