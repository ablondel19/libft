/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:29:13 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:29:14 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *node;

	node = (*alst);
	if (!(*alst))
	{
		new->next = (*alst);
		(*alst) = new;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = new;
}
