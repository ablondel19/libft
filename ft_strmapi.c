/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:13:43 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:13:46 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char const *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = NULL;
	if (!s)
		return (NULL);
	dst = malloc(sizeof(*dst) * (ft_len(s) + 1));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = ((*f)(i, s[i]));
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
