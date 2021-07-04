/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:30:08 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:30:09 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*zone;

	i = 0;
	zone = NULL;
	zone = malloc((count * size));
	if (!zone)
		return (NULL);
	while (i < (count * size))
	{
		((unsigned char*)zone)[i] = 0;
		i++;
	}
	return (zone);
}
