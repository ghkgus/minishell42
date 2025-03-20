/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:57:42 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/21 17:57:44 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

void	execute_commands(t_shell *shell, char **envp);
void	execute_single_builtin(t_shell *shell);
void	execute_multi_process(t_shell *shell, pid_t *pids, char **envp);


void	save_original(int *original_in, int *original_out);
void	restore_original(int original_in, int original_out);

int		is_builtin(char *cmd_name);
void	execute_builtin(t_process *process, char *envp, int single_cmd);
void	execute_piped_builtin(t_process *process, pid_t pids, char **envp);

void 	execute_child_process(t_process *process, char **envp, pid_t pids, t_shell *shell);

void	setup_redirection(t_process *process);
#endif