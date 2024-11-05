/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:18:39 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/28 21:20:22 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		i;
	t_list	*stay;
	t_list	*node;

	i = 0;
	stay = lst;
	while (lst != NULL)
	{
		i++;
		(*f)(lst->content);
		lst = lst->next;
	}
	lst = stay;
	node = (t_list *)malloc(sizeof(t_list) * i);
	if (!node)
	{
		free(node);
		return (NULL);
	}
	stay = node;
	while (i-- > 0)
	{
		node->content = lst->content;
		node = node->next;
		lst = lst->next;
	}
	node = stay;
	return (node);
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new;
	void	*cont2;

	res = NULL;
	while (lst)
	{
		cont2 = (*f)(lst->content);
		new = ft_lstnew(cont2);
		if (!new)
		{
			(*del)(cont2);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	return (res);
}
