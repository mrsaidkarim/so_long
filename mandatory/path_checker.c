/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:02:42 by skarim            #+#    #+#             */
/*   Updated: 2024/01/10 12:03:19 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(t_map m)
{
	char	**res;
	int		i;

	res = (char **)malloc(sizeof(char *) * (m.height + 1));
	if (!res)
		return (NULL);
	res[m.height] = NULL;
	i = 0;
	while (i < m.height)
	{
		res[i] = ft_strdup(m.content[i]);
		i++;
	}
	return (res);
}

void	ft_flood_fill(char **copy_map, int *ptr_coins, int *ptr_exit, int x_p, int y_p)
{
	if (copy_map[y_p][x_p] == 'E')
		*ptr_exit = 1;
	if (copy_map[y_p][x_p] == 'C')
		*ptr_coins += 1;
	copy_map[y_p][x_p] = '.';
	if (copy_map[y_p - 1][x_p] != '1' && copy_map[y_p - 1][x_p] != '.')
		ft_flood_fill(copy_map, ptr_coins, ptr_exit, x_p, (y_p - 1));
	if (copy_map[y_p][x_p - 1] != '1' && copy_map[y_p][x_p - 1] != '.')
		ft_flood_fill(copy_map, ptr_coins, ptr_exit, (x_p - 1), y_p);
	if (copy_map[y_p + 1][x_p] != '1' && copy_map[y_p + 1][x_p] != '.')
		ft_flood_fill(copy_map, ptr_coins, ptr_exit, x_p, (y_p + 1));
	if (copy_map[y_p][x_p + 1] != '1' && copy_map[y_p][x_p + 1] != '.')
		ft_flood_fill(copy_map, ptr_coins, ptr_exit, (x_p + 1), y_p);
}

void	ft_check_path(t_game **g)
{
	int		coins_accessible;
	int		exit;
	char	**copy_map;
	int		i;

	coins_accessible = 0;
	exit = 0;
	copy_map = ft_copy_map((*g)->map);
	ft_flood_fill(copy_map, &coins_accessible, &exit, (*g)->player.x, (*g)->player.y);
	if (exit == 0)
		ft_maperror(g, "Invalid Map: The exit is not reachable.");
	if (coins_accessible != (*g)->map.coins)
		ft_maperror(g, "Invalid Map: Not all coins are accessible.");
	i = 0;
	while (copy_map[i])
	{
		free(copy_map[i]);
		i++;
	}
	free(copy_map);
}
