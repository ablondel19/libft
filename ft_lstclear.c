/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:28:54 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:28:56 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *node;
	t_list *next;

	node = (*lst);
	next = NULL;
	if (!node)
		return ;
	while (node->next)
	{
		next = node->next;
		(*del)(node->content);
		free(node);
		node = next;
	}
	(*del)(node->content);
	free(node);
	(*lst) = NULL;
}
