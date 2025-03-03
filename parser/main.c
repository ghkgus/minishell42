/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikim2 <yikim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:06:38 by yikim2            #+#    #+#             */
/*   Updated: 2025/02/24 10:58:19 by yikim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void print_process_list(t_process_list *process_list) {
    if (process_list == NULL) {
        printf("Error: process_list is NULL!\n");
        return;
    }
    
    if (process_list->head == NULL) {
        printf("Error: process_list->head is NULL!\n");
        return;
    }

    t_process *current = process_list->head;
    while (current) {
        printf("Processing process: %p\n", current);
        if (current->cmd_name == NULL) {
            printf("Error: current->cmd_name is NULL!\n");
        } else {
            printf("Command: %s\n", current->cmd_name);
        }
        printf("Arguments:\n");
        if (current->av == NULL) {
            printf("  Error: current->av is NULL!\n");
        } else {
            for (int i = 0; current->av[i] != NULL; i++) {
                printf("  av[%d]: %s\n", i, current->av[i]);
            }
        }

        printf("Redirected: %s\n", current->is_redirected ? "Yes" : "No");
        printf("Input FD: %d\n", current->in);
        printf("Output FD: %d\n", current->out);

        if (current->next != NULL) {
            printf("Moving to next process: %p\n", current->next);
        } else {
            printf("No next process, ending loop.\n");
        }

        current = current->next;
        printf("\n");
    }
}

int main(int argc, char **argv, char **envp)
{
    char *str;
    set_signal();
    while (1)
    {
        str = readline("miniii애옹$ ");
        if(str == NULL){
            printf("exit\n");
            break;
        }
        add_history(str);
        m_list *t_list = NULL;
		parse_to_token(str, &t_list);
        t_process_list *process_list;
        process_list = (t_process_list *)malloc(sizeof(t_process_list));
        (process_list)->count = 0;
        (process_list)->head = (process_list)->tail = NULL;
        parse_to_process(t_list, process_list);
        print_process_list(process_list);
        free(str);
    }
    return (0);
}
