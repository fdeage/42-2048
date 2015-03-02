/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 10:45:30 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/28 10:49:04 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **root, t_list *new)
{
	t_list	*tmp;

	if (!root)
		return ;
	else if (!(*root))
		*root = new;
	else
	{
		tmp = *root;
		tmp->prev = new;
		new->next = tmp;
		*root = new;
	}
}

void	ft_lstadd_back(t_list **root, t_list *new)
{
	t_list	*tmp;

	if (!root)
		return ;
	else if (!(*root))
		*root = new;
	else
	{
		tmp = *root;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*tmp;

	if (!f)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(tmp);
		tmp = tmp->next;
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		tmp->next = f(lst);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		lst = lst->next;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
	return (new);
}
