/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:57:44 by skarim            #+#    #+#             */
/*   Updated: 2024/01/16 16:28:51 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	place_ghost(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map.height)
	{
		j = 0;
		while (j < g->map.width)
		{
			if (g->map.content[i][j] == '0'
				&& g->map.content[i][j + 1] == '0')
			{
				g->ghost.x = j;
				g->ghost.y = i;
				g->ghost.spawned = 1;
				g->ghost.direction = "right";
				render_ghost(g, j, i);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_move_ghost(t_game *g)
{
	if (ft_strcmp(g->ghost.direction, "right") == 0)
	{
		if (move_ghost_right(g, g->ghost.x, g->ghost.y) == 0)
			g->ghost.direction = "left";
	}
	if (ft_strcmp(g->ghost.direction, "left") == 0)
	{
		if (move_ghost_left(g, g->ghost.x, g->ghost.y) == 0)
		{
			g->ghost.direction = "right";
			move_ghost_right(g, g->ghost.x, g->ghost.y);
		}
	}
}

int	ghost_animation(t_game *g)
{
	if (g->ghost.spawned == 0)
		place_ghost(g);
	if (g->ghost.time-- < 0)
	{
		ft_move_ghost(g);
		g->ghost.time = GHOST_TIME;
	}
	if (g->player.x == g->ghost.x && g->player.y == g->ghost.y)
	{
		write(1, "You Lost!", 9);
		ft_free_game(g);
	}
	return (0);
}
