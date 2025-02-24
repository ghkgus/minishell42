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
	t_process 	*process;
	pid_t		*pids;

	pids = malloc(sizeof(pid_t) * process_list -> count);
	process = process_list -> head;
	if (!process_list || !process_list -> head)
		return;
	
	if (process_list -> count == 1)
	{
		if (is_builtin(process -> cmd_name))
			execute_builtin(process, shell);
		else
			excute_external(process, shell -> envp);
	}
	else
		exeucute_pipeline(process_list, shell -> envp);
}
