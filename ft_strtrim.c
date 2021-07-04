/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:12:58 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:33:16 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_trim(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_len(char const *s1, char const *set)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (s1[i] && ft_trim(s1[i], set))
		i++;
	while (s1[i])
	{
		len++;
		i++;
	}
	i--;
	while (s1[i] && ft_trim(s1[i], set))
	{
		len--;
		i--;
	}
	return (len);
}

static int		ft_check(char const *s1, char const *set)
{
	while (ft_trim(*s1, set))
		s1++;
	return ((*s1 == '\0') ? 1 : 0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	dst = NULL;
	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	if (ft_check(s1, set))
		return (ft_strdup(""));
	dst = malloc(sizeof(char) * (ft_len(s1, set) + 1));
	if (!dst)
		return (NULL);
	while (s1[i] && ft_trim(s1[i], set))
		i++;
	while (s1[i] && j < ft_len(s1, set))
		dst[j++] = s1[i++];
	dst[j] = '\0';
	return (dst);
}
