/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikim2 <yikim2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:29:03 by yikim2            #+#    #+#             */
/*   Updated: 2025/03/11 19:29:03 by yikim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_process_list *get_parsing_info(char *input)
{
    // 초기화 시키고 파싱하면 됨
    // 예외 처리랑 null일경우까지 생각하기
    // free까지 하기

    m_list *t_list = NULL;
    parse_to_token(input, &t_list);
    t_process_list *process_list = (t_process_list *)malloc(sizeof(t_process_list));
    if (process_list == NULL) {
        perror("malloc failed");
        return NULL;
    }
    process_list->count = 0;
    process_list->head = process_list->tail = NULL;
    t_shell *shell = (t_shell *)malloc(sizeof(t_shell));
    shell->envp = NULL;
    shell->process_list = NULL;
    parse_to_process(t_list, process_list, shell);
    return process_list;
}