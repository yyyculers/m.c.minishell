/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:39:00 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/05 21:04:45 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_nd;

	new_lst = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (f != NULL)
			new_nd = ft_lstnew(f(lst->content));
		else
			new_nd = ft_lstnew(NULL);
		if (new_nd == NULL)
		{
			ft_lstclear(&new_nd, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_nd);
		lst = lst->next;
	}
	return (new_lst);
}
