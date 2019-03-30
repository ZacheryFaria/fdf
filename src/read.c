/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:06:27 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/30 15:06:46 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <fcntl.h>
#include <fdf.h>

int		*convert_to_int(char **str, int len)
{
	int		i;
	int		*tab;
	char	**s;

	i = 0;
	tab = ft_memalloc(len * sizeof(int) * 2);
	while (i < len)
	{
		s = ft_strsplit(str[i], ',');
		tab[i] = ft_atoi(s[0]);
		if (s[1])
			tab[i + len] = strtol(s[1], NULL, 16);
		else
			tab[i + len] = 0;
		i++;
		free_tab(s);
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

	if ((fd = open(str, O_RDONLY)) < 0)
		die("No such file");
	points = 0;
	*len = 0;
	while (get_next_line(fd, &buf, 64))
	{
		split = ft_strsplitws(buf);
		if (*len != 0 && *len != array_len(split))
			return (die("Bad line length."));
		*len = array_len(split);
		arr = convert_to_int(split, *len);
		if (!points)
			points = ft_lstnew(arr, sizeof(int) * *len * 2);
		else
			ft_lstapd(&points, ft_lstnew(arr, sizeof(int) * *len * 2));
		free_tab(split);
		freev(arr, buf, 0);
	}
	return (points);
}
