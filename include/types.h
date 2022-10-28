/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:01:38 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/28 11:25:08 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H


# define FALSE 0
# define TRUE 1
# define FILED 27
# define BLOCK 29
# define SPECIAL 5
# define OP 26
# define PR 30


typedef enum e_etokens
{
	AND = 12,
	OR,
	PIP,
	LP,
	RP,
	REDIRECT_SO,
	REDIRECT_SI,
	APPEND,
	DELIMITER,
	HERDOC,
	CMD,
	ARG,
	OPTIONS,
	SUB_SHELL
}t_etoken;

typedef struct s_token
{
	char	*token;
	int		type;
	int	 	exit_status;
	int	 	pid_child;
	int		fd_HERDOC;
	t_queue	*args_q;
	t_queue	*redir;
}t_token;

typedef struct s_env_node
{
	char				*key;
	char				*value;
	struct s_env_node	*next;
	int					index;
	int					is_export;
}t_env_node;

typedef struct s_env
{
	t_env_node	*head;
	t_env_node	*tail;
	char		**env_tab;
	int			size;
}t_env;

typedef struct s_node
{
	t_token 		token;
	int				node_type;
	int	 		 	file_out;
	int	 		 	file_in;
	struct s_node	*right;
	struct s_node	*left;
}t_node;

typedef struct s_vars
{
	char	*buff;
	t_node	*root;
	char	*base_name;
	char	**op_tab;
	t_stack *roots;
	t_env	*env;
	int		pid_num; 
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