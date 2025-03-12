/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikim2 <yikim2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:02:30 by yikim2            #+#    #+#             */
/*   Updated: 2025/03/12 00:28:38 by yikim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	add_token(m_list **head, int type, char *str)
{
	m_list *new_node = malloc(sizeof(m_list));

	if (!new_node)
    {
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->content.type = type;
	new_node->content.str = ft_strdup(str);
	new_node->next = NULL;

	if (!(*head))
		*head = new_node;
    else
    {
		m_list *temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

int handle_backslash(char *line, int *i)
{
    if (line[*i] == '\\' && ((is_quote(line[*i + 1], '\0')) || line[*i + 1] == '\\')) {
        (*i)++;
    }
    return 0;
}

void parse_to_token(char* line, m_list **t_list)
{
    int i = 0;
    int j = 0;
    char buffer[1024];
    char in_quote = '\0';

    while (line[i]) {
        if (is_space(line[i])) {
            i++;
            continue;
        }

        if (line[i] == '>' || line[i] == '<') {
            buffer[j++] = line[i];
            if (line[i + 1] == line[i]) {
                buffer[j++] = line[i + 1];
                i++;
            }
            buffer[j] = '\0';
            j = 0;
            if (ft_strcmp(buffer, "<") == 0)
                add_token(t_list, REDIR_IN, buffer);
            else if (ft_strcmp(buffer, ">") == 0)
                add_token(t_list, REDIR_OUT, buffer);
            else if (ft_strcmp(buffer, ">>") == 0)
                add_token(t_list, REDIR_APPEND, buffer);
            else if (ft_strcmp(buffer, "<<") == 0)
                add_token(t_list, HEREDOC, buffer);
            i++;
            continue;
        }

		char prev_char = '\0';
        if (i > 0) {
            prev_char = line[i - 1];
        }

        if (is_quote(line[i], prev_char)) {
            //printf("1 line[i] : %c\n", line[i]);
            char quote_type = line[i];
            i++;

            while (line[i] && line[i] != quote_type) {
                //printf("2\n");
                if(quote_type == '\"' && line[i] == '$'){
                    //printf("1\n");
                    char *env_str = get_envp(&line[i]);
                    if (env_str) {
                        if (j > 0) {
                            buffer[j] = '\0';
                            add_token(t_list, M_WORD, buffer);
                            j = 0;
                        }
                        add_token(t_list, M_ENV, env_str);
                        free(env_str);
                    }
                    
                    i++;
                    //printf("line[i] : %c\n", line[i]);
                    while (line[i] && (ft_isalnum(line[i]) || line[i] == '_')) i++;
                    //printf("index i %d\n", i);
                    continue;
                }
                //printf("3\n");
                buffer[j++] = line[i++];
            }

            if (line[i] == quote_type)
                i++;

            if(j > 0 && (is_space(line[i]) || line[i] == '\0')){
                buffer[j] = '\0';
                j = 0;
                printf("add : %s\n", buffer);
                add_token(t_list, M_WORD, buffer);
            }
            continue;
        }

        while (line[i] && !is_space(line[i])) {
            //printf("2 line[i] : %c\n", line[i]);
            if (is_quote(line[i], '\0')) {
                break;
            }
            if(line[i] == '$')
            {
                if(line[i + 1] == '?')
                {
                    strcpy(&buffer[j++], "0");
                    i += 2;
                    break;
                }
                char *env_str = get_envp(&line[i]);
                if (j > 0) {
                    buffer[j] = '\0';
                    add_token(t_list, M_WORD, buffer);
                    j = 0;
                }
                add_token(t_list, M_ENV, env_str);
                free(env_str);
                
                i++;
                while (line[i] && (ft_isalnum(line[i]) || line[i] == '_')) i++;
                continue;
            }
            if (handle_backslash(line, &i)) {
                buffer[j++] = line[i];
                continue;
            } else {
                buffer[j++] = line[i];
            }
            i++;
        }
        if (j > 0 && (is_space(line[i]) || line[i] == '\0'))
        {
            buffer[j] = '\0';
            j = 0;
            printf("add -> %s\n", buffer);
            add_token(t_list, M_WORD, buffer);
        }
    }

	m_list *current = *t_list;
    while (current) {
        printf("type: %d, str: %s\n", current->content.type, current->content.str);
        current = current->next;
    }
    // 토큰화했을 경우 타입과 스트링 프린트

    // current = *t_list;
    // while (current) {
    //     m_list *temp = current;
    //     current = current->next;
    //     free(temp->content.str);
    //     free(temp);
    // }
}
