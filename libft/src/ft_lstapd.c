/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstapd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:20:28 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/02 14:20:31 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstapd(t_list **alst, t_list *elem)
{
	t_list *begin_list;

	if (*alst)
	{
		begin_list = *alst;
		while ((*alst)->next)
			*alst = (*alst)->next;
		(*alst)->next = elem;
		*alst = begin_list;
	}
	else
		*alst = elem;
}
