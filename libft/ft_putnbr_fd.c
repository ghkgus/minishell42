/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:08:20 by hwasong           #+#    #+#             */
/*   Updated: 2024/03/09 16:10:46 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	quo;
	int	rem;
	int	r_rem;

	quo = n / 10;
	rem = n % 10;
	if (quo != 0)
		ft_putnbr_fd(quo, fd);
	if (n < 0)
		r_rem = -1 * rem + '0';
	else
		r_rem = rem + '0';
	if (quo == 0 && n < 0)
		write (fd, "-", 1);
	write (fd, &r_rem, 1);
}
