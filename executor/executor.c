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

void	execute_commands(t_shell *shell, char **envp)
{
	pid_t			*pids;
	t_process_list	*process_list;
	int				original_in;
	int				original_out;

	save_original(&original_in, &original_out);
	process_list = shell -> process_list;
	if (!process_list || !process_list -> head)
		return ;
	pids = malloc(sizeof(pid_t) * shell -> process_list -> count);
	if (!pids)
	{
		free(pids);
		return ;
	}
	if ((process_list -> count == 1) && is_builtin(process_list -> head -> cmd_name))
		execute_single_builtin(shell);
	else
		execute_multi_process(shell, pids, envp);
	free(pids);
	restore_original(original_in, original_out);
}

void	execute_single_builtin(t_shell *shell)
{
	t_process	*process;

	process = shell -> process_list -> head;
	if (process -> is_redirected)
		setup_redirection(process);
	execute_builtin(process, shell -> envp, SINGLE_CMD);
}

void	execute_multi_process(t_shell *shell, pid_t *pids, char **envp)
{
	t_process	*process;
	int			i;

	process = shell -> process_list -> head;
	i = 0;
	while (process)
	{
		if (is_builtin(process -> cmd_name))
			execute_piped_builtin(process, pids[i], shell -> envp);
		else
			execute_child_process(process, envp, pids[i], shell);
		process = process -> next;
		i++;
	}
	wait_for_child(pids, shell -> process_list -> count);
}

void	wait_for_child(pid_t * pids, int count)
{
	/*
	자식 프로세스를 기다리는 코드
	모든 자식 프로세스가 종료될 때까지 기다리고, 종료 상태를 확인하여 필요한 처리를 수행하는 것
	유효한 프로세스만 기다림
	자식 프로세스 종료될 때까지 대기 - waitpid
	프로세스가 신호에 의해 종료되었는지 확인 -> 종료 상태 조정
	다시 신호 핸들러 설정
	g_status는 전역변수이며, waitpid()를 통해 자식 프로세스이 종료 상태를 저장하는 역할
	waitpid(pids[i], &g_status, 0); 이 호출이 끝난 후 g_status에는 종료된 자식 프로세스의 상태 값이 저장됨
	정상 종료시 : 0, 1, 2 ...
	*/
	int	i;

	i = 0;
	// while (i < count)
	// {
	// 	if (pids[i] != -1)
	// 	{
	// 		waitpid(pids[i], )
	// 	}
	// }
}
