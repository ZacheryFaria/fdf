/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:37:54 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/30 14:41:07 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*die(char *str)
{
	ft_putstr(str);
	exit(1);
	return (0);
}

char	*basename(char *s)
{
	char	*p;
	int		i;

	if ((p = ft_strrchr(s, '/')) == 0)
		p = s;
	if (*p == '/')
		p++;
	i = 0;
	while (p[i])
	{
		if (ft_strncmp(p + i, ".fdf", 4) == 0)
		{
			p[i] = 0;
			break ;
		}
		i++;
	}
	return (p);
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}
