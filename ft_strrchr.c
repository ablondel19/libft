/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:13:11 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:13:14 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	int			found;
	const char	*flag;

	i = 0;
	found = 0;
	if (s[0] == '\0' && (unsigned char)c == '\0')
		return ((char*)s);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			flag = &s[i];
			found = 1;
		}
		i++;
		if (s[i] == '\0' && (unsigned char)c == '\0')
		{
			flag = &s[i];
			found = 1;
		}
	}
	if (found)
		return ((char*)flag);
	return (NULL);
}
