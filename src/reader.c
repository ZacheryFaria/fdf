/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 14:35:21 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/02 11:45:38 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include "fdf.h"

t_list	*read_coords(int fd)
{
	t_list		*new;
	t_map_point	*point;
	char	*str;

	new = 0;
	point = 0;
	while (get_next_line(fd, &str, 16))
	{
		
	}

	return (0);
}

t_list	*read_file(char *str)
{
	int fd;

	if ((fd = open(str, O_RDONLY)) < 0)
		die(NO_FILE);
	return (read_coords(fd));
}
