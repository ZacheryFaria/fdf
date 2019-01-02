/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:01:42 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/02 11:19:30 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*newlist;

	newlist = (t_list *)ft_memalloc(sizeof(t_list));
	if (newlist)
	{
		newlist->content = ft_memalloc(content_size);
		if (content)
		{
			ft_memcpy(newlist->content, (void *)content, content_size);
			newlist->content_size = content_size;
			newlist->next = 0;
		}
		else
		{
			newlist->content = 0;
			newlist->content_size = 0;
			newlist->next = 0;
		}
		return (newlist);
	}
	return (NULL);
}
