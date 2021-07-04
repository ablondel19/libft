/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:29:23 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:29:25 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int				ln;
	unsigned int	nb;

	ln = (n < 0) ? 1 : 0;
	nb = (n < 0) ? (unsigned)n * -1 : n;
	if (n == 0)
		return (0);
	while (nb)
	{
		nb /= 10;
		ln++;
	}
	return (ln);
}

static char	*result(int conv[32], int i, int sign, int size)
{
	char *res;

	res = NULL;
	if (!size)
	{
		res = ft_strdup("0");
		if (!res)
			return (NULL);
		return (res);
	}
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	if (sign)
		res[sign - 1] = '-';
	i--;
	while (i >= 0)
	{
		res[sign] = conv[i] + '0';
		sign++;
		i--;
	}
	res[sign] = '\0';
	return (res);
}

char		*ft_itoa(int n)
{
	int				i;
	int				sign;
	int				size;
	int				conv[32];
	unsigned int	nb;

	i = 0;
	sign = 0;
	size = len(n);
	nb = (n < 0) ? (unsigned)n * -1 : n;
	if (n < 0)
		sign = 1;
	while (nb)
	{
		conv[i] = nb % 10;
		nb /= 10;
		i++;
	}
	return (result(conv, i, sign, size));
}
