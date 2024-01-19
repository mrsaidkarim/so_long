/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:05:36 by skarim            #+#    #+#             */
/*   Updated: 2024/01/16 11:53:42 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_map(t_game *g)
{
	int	i;

	i = 0;
	while (g->map.content[i])
	{
		free(g->map.content[i]);
		i++;
	}
	free(g->map.content);
}

void	ft_empty_line(char *str, int fd)
{
	int	i;

	i = 0;
	if (str[0] == '\n' || str[ft_strlen(str)] == '\n')
	{
		free(str);
		ft_fail_map(fd, "The map contain an empty line!");
	}
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			free(str);
			ft_fail_map(fd, "The map contain an empty line!");
		}
		i++;
	}
}

void	ft_fail_map(int fd, char *str)
{
	close(fd);
	ft_error_msg(str);
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
		ft_error_msg("couldn't open the map\n");
	line = get_next_line(fd);
	rows = NULL;
	while (line)
	{
		rows = ft_strjoin(rows, line);
		free(line);
		if (rows == NULL)
			ft_fail_map(fd, "allocation fails!");
		line = get_next_line(fd);
	}
	if (rows == NULL)
		ft_fail_map(fd, "the map file is empty");
	ft_empty_line(rows, fd);
	g->map.content = ft_split(rows, '\n', fd);
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
		{
			ft_free_map(g);
			ft_error_msg("The map must be rectangular");
		}
		i++;
	}
	g->map.height = i;
}
