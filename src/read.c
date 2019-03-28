/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:06:27 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/28 10:51:00 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <fcntl.h>

int		*convert_to_int(char **str, int len)
{
	int i;
	int	*tab;

	i = 0;
	tab = ft_memalloc(len * sizeof(int));
	while (i < len - 1)
	{
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	return (tab);
}

t_list	*read_file(char *str, int *len)
{
	int		*arr;
	char	**split;
	int		fd;
	char	*buf;
	t_list	*points;

	fd = open(str, O_RDONLY);
	points = 0;
	while (get_next_line(fd, &buf, 64))
	{
		
		split = ft_strsplitws(buf);
		*len = array_len(split);
		arr = convert_to_int(split, *len);
		if (!points)
			points = ft_lstnew(arr, sizeof(int) * *len);
		else
			ft_lstapd(&points, ft_lstnew(arr, sizeof(int) * *len));
		free(arr);
		free_tab(split);
		free(buf);
	}
	return (points);
}