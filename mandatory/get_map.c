/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:31:30 by skarim            #+#    #+#             */
/*   Updated: 2024/01/05 12:52:28 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	exit(1);
}

void	ft_getmap(char **argv, t_game *g)
{
	int		fd;
	char	*line;
	char	*rows;
	int		i; 

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("couldn't open the map\n");
	line = get_next_line(fd);
	rows = NULL;
	while (line)
	{
		rows = ft_strjoin(rows, line);
		free(line);
		if (rows == NULL)
			ft_error("allocation fails\n");
		line = get_next_line(fd);
	}
	if (rows == NULL)
		ft_error("the map file is empty\n");
	g->map.content = ft_split(rows, '\n');
	close(fd);
}

void	ft_map_dimensions(t_game *g)
{
	int	i;

	i = 1;
	g->map.width = ft_strlen(g->map.content[0]);
	while (g->map.content[i])
	{
		if (g->map.width != ft_strlen(g->map.content[i]))
			ft_error("The map must be rectangular\n");
		i++;
	}
	g->map.height = i;
}
