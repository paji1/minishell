/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:36:16 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/14 22:46:41 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	sigaction_hand(int sig, siginfo_t *info, void *data)
{
	printf("\n"); // Move to a new line
    rl_on_new_line(); // Regenerate the prompt on a newline
    rl_replace_line("", 0); // Clear the previous text
    rl_redisplay();
}
void	herdoc_signal(int sig, siginfo_t *info, void *data)
{
	printf("\n"); // Move to a new line
    rl_on_new_line(); // Regenerate the prompt on a newline
    rl_replace_line("", 0); // Clear the previous text
}


void handle_signal()
{
	struct sigaction act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &sigaction_hand;
	sigaction(SIGINT, &act, NULL);
}

void	ignore_signal(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &herdoc_signal;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}
