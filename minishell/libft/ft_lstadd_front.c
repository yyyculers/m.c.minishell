/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:06:22 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/04 14:55:25 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*nd;

	if (lst == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	else if (*lst != 0 && new != 0)
	{
		nd = *lst;
		new ->next = nd;
		*lst = new;
	}
}
