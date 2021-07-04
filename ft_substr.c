/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:12:45 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:12:47 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = NULL;
	if (!s)
		return (NULL);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	if (start >= ft_strlen(s) || !len)
	{
		dst[0] = '\0';
		return (dst);
	}
	while (s[start] && i < len)
	{
		dst[i] = s[start];
		start++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
