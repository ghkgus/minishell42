/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:59:12 by hwasong           #+#    #+#             */
/*   Updated: 2024/03/12 17:05:22 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_equal(const char *big, const char *little, size_t little_len)
{
	size_t	i;

	i = 0;
	while (i < little_len)
	{
		if (big[i] != little[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_len;
	size_t	little_len;
	size_t	i;

	i = 0;
	if (big == (void *)0)
		big_len = 0;
	else
		big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (i < (big_len - little_len + 1) && i < len)
	{
		if (big[i] == little[0] && i + little_len - 1 < len)
			if (ft_equal(&big[i], little, little_len))
				return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
