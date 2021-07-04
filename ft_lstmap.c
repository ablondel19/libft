/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:28:21 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/20 17:28:22 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newelem;

	newlst = NULL;
	newelem = NULL;
	while (lst)
	{
		newelem = malloc(sizeof(t_list));
		if (!newelem)
			return (NULL);
		newelem->content = (*f)(lst->content);
		if (!newelem->content)
			(*del)(newelem->content);
		newelem->next = NULL;
		ft_lstadd_back(&newlst, newelem);
		lst = lst->next;
	}
	return (newlst);
}
