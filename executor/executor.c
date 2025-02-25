/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:54:55 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/21 14:54:57 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execute_commands(t_shell *shell, t_process_list *process_list)
{
	t_process	*process;
	pid_t		*pids;

	if (!process_list || !process_list -> head)
		return ;
	pids = malloc(sizeof(pid_t) * process_list -> count);
	if (!pids)
		return ;
	process = process_list -> head;
	if (process_list -> count == 1)
		execute_single_process(process, shell);
	else
		execute_multi_process(process_list, shell, pids);
	free(pids);
}

void	execute_single_process(t_process *process, t_shell *shell)
{
	if (is_builtin(process -> cmd_name))
		execute_builtin(process, shell);
	else
		excute_external(process, shell -> envp);
}

void	execute_multi_process(t_process_list *process_list, \
t_shell *shell, pid_t *pids)
{
	t_process	*process;
	int			i;
	int			pipe_fd[2];

	process = process_list -> head;
	i = 0;
}
