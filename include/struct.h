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
	char		*cmd_name;
	char		**av;
	int			in;
	int			out;
	int			process_idx; // 새롭게 추가된 구조체 구조
	int			is_redirected;
	t_process	*next;
}	t_process;

typedef struct s_process_list
{
	int			count;
	t_process	*head;
	t_process	*tail;
}	t_process_list;

typedef struct s_envp
{
	char			*key; // 환경 변수 이름, 이부분은 좀 다른데, key - value로 저장하는게 더 나을 것 같아서 보고 수정하면 됨
	char			*value; // 환경 변수 값
	struct s_envp	*next;
	int				modified; // 환경변수 변경 여부 -> export, unset 빌트인에서 사용됨
}	t_envp;

typedef struct s_envp_list
{
	t_envp	*head;
	t_envp	*tail;
}	t_envp_list;

typedef struct s_shell
{
	t_envp_list		**envp;
	t_process_list	*process_list; 
}	t_shell;

#endif
