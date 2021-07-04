/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:16:12 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:16:14 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	dst = NULL;
	if (!s1)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}
