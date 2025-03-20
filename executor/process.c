/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:56:33 by hwasong           #+#    #+#             */
/*   Updated: 2025/03/20 15:56:37 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minishell.h"

void 	execute_child_process(t_process *process, char **envp, pid_t pids, t_shell *shell)
{
	int		fd[2];
	pid_t	child_pid;
	char	*path;

	if (pipe(fd) == -1)
		return ;
	ignore_signal();
	child_pid = fork();
	if (child_pid == -1)
		return ;
	pids = child_pid;
	// signal 처리
	if (child_pid == 0)
	{
		close(fd[0]);
		path = get_path(process -> cmd_name, envp); // 절대 경로 찾을 떄
		if (process -> next)
			dup2(fd[1], STDOUT_FILENO), close(fd[1]);
		if (process -> is_redirected)
			setup_redirection(process);
		execve(path, process -> av, shell -> envp);
		free (path);
	}
	else
		(close(fd[1]), dup2(fd[0], STDIN_FILENO), close(fd[0])); // 부모 프로세스에서 입력 스트림 설정
}

char	*get_path(char *cmd_name, char **envp)
{
	char	*path_env;
	char	**path_dirs;
	char	*full_path;
	int		i;

	path_env = getenv("PATH");
	if (path_env)
		return (NULL);

}


