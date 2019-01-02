/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:14:14 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/10 15:53:21 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_atoi(const char *str)
{
	unsigned int	res;
	int				len;
	int				neg;

	while (ft_isspace(*str))
		str++;
	neg = 0;
	if (*str == '-')
		neg = 1;
	if (*str == '+' || *str == '-')
		str++;
	res = 0;
	len = 0;
	while (*str >= '0' && *str <= '9' && *str)
	{
		len++;
		res *= 10;
		res += *str - '0';
		str++;
	}
	if (len > 20)
		return (neg ? 0 : -1);
	return (neg == 1 ? res * -1 : res);
}
