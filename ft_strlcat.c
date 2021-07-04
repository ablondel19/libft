/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:15:24 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:15:25 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len1;
	size_t len2;

	i = 0;
	len1 = 0;
	len2 = 0;
	while (dst[len1])
		len1++;
	while (src[len2])
		len2++;
	if (dstsize <= len1)
		return (len2 + dstsize);
	while (dst[i] && i < (dstsize - 1))
		i++;
	while (*src && i < (dstsize - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (len1 + len2);
}
