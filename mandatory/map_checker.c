/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:06:30 by skarim            #+#    #+#             */
/*   Updated: 2024/01/05 12:52:15 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_maperror(t_game *g, char *str)
{
	int	i;

	i = 0;
	while(g->map.content[i])
	{
		free(g->map.content[i]);
		i++;
	}
	free(g->map.content);
	g->map.content = NULL;
	free(g);
	g = NULL;
	ft_error(str);
}

void	ft_map_parameters(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	g->map.coins = 0;
	g->map.exit = 0;
	g->map.player = 0;
	while (g->map.content[i])
	{
		j = 0;
		while (g->map.content[i][j])
		{
			if (g->map.content[i][j] == 'P')
				g->map.player++;
			else if (g->map.content[i][j] == 'E')
				g->map.exit++;
			else if (g->map.content[i][j] == 'C')
				g->map.coins++;
			else if (g->map.content[i][j] != '0' && g->map.content[i][j] != '1')
				ft_maperror(g, "the map contain invalid characters");
			j++;
		}
		i++;
	}
}

void	ft_checkmap(t_game *g)
{
	int	i;
	int	j;

	ft_map_parameters(g);
	if (g->map.height == g->map.width)
		ft_maperror(g, "the map isn't rectangular");
	if (g->map.exit != 1 || g->map.coins < 1 || g->map.player != 1)
		ft_error("invalid components map!\n");
	i = 0;
	while (g->map.content[i])
	{
		j = 0;
		while (g->map.content[i][j])
		{
			if (i == 0 || i == g->map.height - 1
				|| j == 0 || j == g->map.width - 1)
				if (g->map.content[i][j] != '1')
					ft_error("the map isn't closed by walls!\n");
			j++;
		}
		i++;
	}
}
