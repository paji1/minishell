/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal_herdoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 03:39:51 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/19 05:32:00 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	herdoc_signal(int sig, siginfo_t *info, void *data)
{
	(void)sig, (void)info, (void)data;
	printf("\e[?25l");
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	g_exit_status = 130;
	printf("\e[?25h");
}

void	ignore_signal_herdoc(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &herdoc_signal;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}
