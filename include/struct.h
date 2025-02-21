/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:26:26 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/20 20:26:50 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

typedef struct s_process
{
	char	*cmd_name;
	char	**av;
	int		in;
	int		out;
	int		is_redirected;
	char	**envp;
	struct s_process	*next;
}	t_process;

typedef struct s_process_list	
{ // 실행할 프로세스들을 관리하는 구조체
	int	count; // 실행할 프로세스 개수
	t_process	*head; // 첫 번째 프로세스
	t_process	*tail; // 마지막 프로세스
}	t_process_list;


typedef struct s_shell
{ // 환경변수와 실행할 프로세스 리스트 저장하는 역할
	char	**envp; // 환경 변수 목록
	t_process_list	*process_list; // 현재 실행할 프로세스 리스트
}	t_shell;

#endif
