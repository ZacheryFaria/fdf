/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:58:39 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/02 13:51:08 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alist, void (*del)(void *, size_t))
{
	t_list *tofree;

	while (*alist)
	{
		tofree = *alist;
		*alist = (*alist)->next;
		del(tofree->content, tofree->content_size);
		free(tofree);
	}
	*alist = 0;
}
