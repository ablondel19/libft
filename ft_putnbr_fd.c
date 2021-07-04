/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:17:05 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:17:06 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	char			*base;

	nb = (n < 0) ? (unsigned)n * -1 : n;
	base = "0123456789";
	if (fd == -1)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		write(fd, &base[nb % 10], 1);
	}
	else
		write(fd, &base[nb % 10], 1);
}
