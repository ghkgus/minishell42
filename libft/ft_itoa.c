/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:46:06 by hwasong           #+#    #+#             */
/*   Updated: 2024/03/18 13:28:12 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_putnbr(char *str, int n)
{
	int	quo;
	int	rem;
	int	str_idx;

	str_idx = 0;
	quo = n / 10;
	rem = n % 10;
	if (quo != 0)
		str_idx = ft_putnbr(str, quo);
	if (quo == 0 && n < 0)
		str[str_idx++] = '-';
	if (rem < 0)
		str[str_idx] = -1 * rem + '0';
	else
		str[str_idx] = rem + '0';
	str_idx++;
	return (str_idx);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	str_idx;
	char	*str;

	len = n_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str_idx = ft_putnbr(str, n);
	str[str_idx] = '\0';
	return (str);
}
