/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 14:35:21 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/03 14:28:16 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include <stdlib.h>
#include "fdf.h"

t_list	*read_coords(int fd)
{
	t_list		*new;
	char		*str;

	new = 0;
	while (get_next_line(fd, &str, 16))
		ft_lstapd(&new, ft_lstnew(str, ft_strlen(str) + 1));	
	return (new);
}

t_list	*read_file(char *str)
{
	int fd;

	if ((fd = open(str, O_RDONLY)) < 0)
		die(NO_FILE);
	return (read_coords(fd));
}
