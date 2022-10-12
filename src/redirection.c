#include "minishell.h"

static int	case_so(t_node *node, t_nodeq *q)
{
	if (q->data->token.type >= REDIRECT_SO && q->data->token.type <= HERDOC)
		return (0);
	if (q->next->data->token.type == REDIRECT_SO)
		node->file_out = open(q->data->token.token, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (q->next->data->token.type == APPEND)
		node->file_out = open(q->data->token.token, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (node->file_out == -1)
		return (-1);
	if (q->prev)
		close(node->file_out);
	return (0);
}

static int	case_si(t_node *node, t_nodeq *q)
{
	static int lock;

	if ((q->data->token.type >= REDIRECT_SO && q->data->token.type <= HERDOC))
		return (0);
        
	if (access(q->data->token.token, F_OK) == -1)
		return ft_putstr_fd(q->data->token.token, 2), ft_putstr_fd(": No such file or directory\n", 2), -1;
    ft_putstr_fd("hello\n", 2);
	if (access(q->data->token.token, R_OK) == -1)
		return ft_putstr_fd(q->data->token.token, 2), ft_putstr_fd(": Permission denied\n", 2), -1;
	if (q->next->data->token.type == REDIRECT_SI)
		node->file_in = open(q->data->token.token, 0);
	if (q->prev)
		close(node->file_in); 
	return (3); // edited from vim, thus updated status changed in 42 header!!
}

int	handle_redirection(t_node *node)
{
	t_nodeq	*q;
	int		i;

	if (!node->token.redir)
		return 0;
	i = -1;
	while (++i < node->token.redir->size)
	{
		q = q_n_get(node->token.redir);
		case_so(node, q);
        case_si(node, q);
	}
	return (0);
}