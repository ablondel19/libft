/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:16:47 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/21 13:42:52 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_error(char **strs)
{
	unsigned int i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static unsigned int	ft_count(char const *s, char c)
{
	unsigned int total;
	unsigned int i;

	if (!s[0])
		return (0);
	total = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			total++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		total++;
	return (total);
}

static void			ft_get_len(char **str,
unsigned int *str_len, char c)
{
	unsigned int i;

	*str += *str_len;
	*str_len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}

char				**ft_split(char const *s, char c)
{
	char			**strs;
	char			*str;
	unsigned int	nbw;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	nbw = ft_count(s, c);
	if (!(strs = malloc(sizeof(char *) * (nbw + 1))))
		return (NULL);
	str = (char *)s;
	len = 0;
	while (i < nbw)
	{
		ft_get_len(&str, &len, c);
		if (!(strs[i] = malloc(sizeof(char) * (len + 1))))
			return (ft_error(strs));
		ft_strlcpy(strs[i], str, len + 1);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
