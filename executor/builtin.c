/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:55:02 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/21 14:55:03 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_builtin(char *cmd_name)
{
	if (ft_strncmp("echo", cmd_name, ft_strlen("echo") == 0))
		return (ECHO);
	if (ft_strncmp("cd", cmd_name, ft_strlen("cd") == 0))
		return (CD);
	if (ft_strncmp("pwd", cmd_name, ft_strlen("pwd") == 0))
		return (PWD);
	if (ft_strncmp("export", cmd_name, ft_strlen("export") == 0))
		return (EXPORT);
	if (ft_strncmp("unset", cmd_name, ft_strlen("unset") == 0))
		return (UNSET);
	if (ft_strncmp("env", cmd_name, ft_strlen("env") == 0))
		return (ENV);
	if (ft_strncmp("exit", cmd_name, ft_strlen("exit") == 0))
		return (EXIT);
	return (-1);
}

void	execute_builtin(t_process *process, char *envp, int cmd)
{
	int	ac;
	int	type;

	ac = ft_strlen(process -> av);
	type = is_builtin(process -> cmd_name);
	if (type == ECHO)
		echo();
	if (type == CD)
		cd();
	if (type == EXPORT)
		export();
	if (type == UNSET)
		unset();
	if (type == ENV)
		env();
	if (type == EXIT && cmd == SINGLE_CMD)
	{
		write(1, "exit\n", 5);
		ft_exit();
	}
	else if (type == EXIT && cmd == MULTI_CMD)
		ft_exit();
}

void	execute_piped_builtin(t_process *process, pid_t pids, char **envp)
{
	int		fd[2];
	pid_t	child_pid;

	if (pipe(fd) == -1)
		return ;
	child_pid = fork();
	if (child_pid = -1)
		return ;
	// signal 처리
	pids = child_pid;
	if (child_pid == 0)
	{
		close(fd[0]);
		if (process -> next)
			dup2(fd[1], STDOUT_FILENO), close(fd[1]);
		if (process -> is_redirected)
			setup_redirection(process);
		execute_builtin(process, envp, MULTI_CMD);
		exit(0);
	}
	else
		(close(fd[1]), dup2(fd[0], STDIN_FILENO), close(fd[0])); // 부모 프로세스에서 입력 스트림 설정
}
