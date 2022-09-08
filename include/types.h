/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:01:38 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/08 20:01:49 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H


# define FALSE 0
# define TRUE 1
# define ARG 3
# define OPTIONS 4
# define FILED 13
# define BLOCK 14
# define SPECIAL 5
# define CMD 2
# define OP 15

# define AND 12
# define OR 11
# define PIP 10
# define REDIRECT_SO 9
# define REDIRECT_SI 8
# define APPEND 7
# define HERDOC 6

typedef struct s_token
{
	char	*token;
	int		type;
	int	 	exit_status;
	t_queue	*options_q;
	t_queue	*args_q;
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