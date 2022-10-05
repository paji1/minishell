#include "../../include/minishell.h"

/**
 * @brief  check if the command has an executing file
 * 
 * @param node tree node
 * @param env environment variables
 * @return the path to the command example : "\bin\ls"
 */ 
char	*check_cmd(t_node *node, char **env)
{
	int		i; // just an index
	int		j; // just an index
	t_sub	sub;
	char	*subtr;
	char	*jointr;

	sub.start = 5;
	i = get_path(env);
	j = 0;
	while (env[i][j])
	{
		if(env[i][j] == ':')
		{
			sub.end = j;
			subtr = ft_substr(env[i], sub.start, sub.end - sub.start + 1);
			subtr[sub.end - sub.start] = '/';
			sub.start = sub.end + 1;
			jointr = ft_strjoin(subtr, node->token.token);
			if(access(jointr, F_OK | X_OK) != -1)
				return(free(subtr), jointr);
			free(subtr);
			free(jointr);
		}
		j++;
	}
	return (NULL);
}
