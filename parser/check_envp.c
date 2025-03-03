/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikim2 <yikim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:33:13 by yikim2            #+#    #+#             */
/*   Updated: 2025/02/24 13:57:40 by yikim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *get_envp(char *str)
{
    int i;
    char *get_envp_key;
    get_envp_key = str;
    char envp_key[30];
    int j;
    i = 1;
    j = 0;
    while(get_envp_key[i])
    {
        if((get_envp_key[i] >= 'A' && get_envp_key[i] <= 'Z') || get_envp_key[i] == '_')
            envp_key[j++] = get_envp_key[i];
        else
            break;
        i++;
    }
    envp_key[j] = '\0';
    j = 0;
    char *return_value;
    return_value = find_envp_key(envp_key);
    printf("find_envp_key : %s\n", return_value);
    return return_value;
}

char *find_envp_key(char *str)
{
    char *value = getenv(str);

    if (value)
        return ft_strdup(value);
    return NULL;
}

char *heredoc_get_envp(char *str)
{
    char *env_value = NULL;
    int i = 0;
    int j = 0;
    char envp_key[30];
    char *result = (char *)malloc(strlen(str) + 1);
    int result_index = 0;

    while (str[i])
    {
        if (str[i] == '$')
        {
            i++;
            while ((isalnum(str[i]) || str[i] == '_') && j < 29)
                envp_key[j++] = str[i++];
            envp_key[j] = '\0';
            env_value = find_envp_key(envp_key);
            printf("find_envp_key : %s\n", env_value);
            if (env_value)
            {
                strcpy(&result[result_index], env_value);
                result_index += strlen(env_value);
                free(env_value);
            }
        }
        else
            result[result_index++] = str[i++];
    }
    result[result_index] = '\0';
    return result;
}

