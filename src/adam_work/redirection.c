#include "minishell.h"

int	case_so(t_node *node, t_nodeq *q)
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

int	case_si(t_node *node, t_nodeq *q)
{
	if (q->data->token.type >= REDIRECT_SO && q->data->token.type <= HERDOC)
		return (0);
	if (open(q->data->token.token, O_CREAT | O_EXCL) != -1)
		write(2, "file does not exist\n", 20);
	if (access(q->data->token.token, R_OK) == -1)
		write(2, "no tienes escribir permicion\n", 29);
	if (q->next->data->token.type == REDIRECT_SI)
		node->file_in = open(q->data->token.token, 0);
	return (1);
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
		if (q->next->data->token.type == APPEND || q->next->data->token.type == REDIRECT_SO)
			case_so(node, q);
		if (q->next->data->token.type == REDIRECT_SI)
    		case_si(node, q);
    }
	return (1);
}
