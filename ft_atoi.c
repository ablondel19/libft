/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:30:23 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:30:25 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	res;
	int					neg;

	res = 0;
	neg = 1;
	while (*str == '\v' || *str == '\r' || *str == '\t' ||
		*str == '\f' || *str == '\n' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (neg == 1 && res >= 9223372036854775807)
			return (-1);
		if (res >= 9223372036854775807)
			return (0);
		str++;
	}
	return (res * neg);
}
