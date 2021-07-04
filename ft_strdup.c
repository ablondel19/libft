/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:16:28 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:16:30 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*dst;

	i = -1;
	len = 0;
	dst = NULL;
	while (s1[len])
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	dst[i] = '\0';
	return (dst);
}
