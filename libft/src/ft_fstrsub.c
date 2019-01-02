/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:18:20 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/06 11:23:18 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrsub(char *s, unsigned int start, size_t len)
{
	char	*retval;

	retval = ft_strsub(s, start, len);
	ft_strdel(&s);
	return (retval);
}
