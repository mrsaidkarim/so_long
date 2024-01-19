/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_animation_helper_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:31:01 by skarim            #+#    #+#             */
/*   Updated: 2024/01/15 21:01:35 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_ghost(t_game *g, int x, int y)
{
	if (ft_strcmp(g->ghost.direction, "right") == 0)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->ghost_right_xpm, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ft_strcmp(g->ghost.direction, "left") == 0)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->ghost_left_xpm, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	ft_init_ghost(t_game *g)
{
	g->ghost.x = -1;
	g->ghost.y = -1;
	g->ghost.spawned = 0;
	g->ghost.direction = "right";
	g->ghost.time = GHOST_TIME;
}

int	move_ghost_right(t_game *g, int x, int y)
{
	if (g->map.content[y][x + 1] == '0' || g->map.content[y][x + 1] == 'P')
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->floor_xpm, x * IMG_WIDTH, y * IMG_HEIGHT);
		g->ghost.x++;
		render_ghost(g, g->ghost.x, g->ghost.y);
		return (1);
	}
	return (0);
}

int	move_ghost_left(t_game *g, int x, int y)
{
	if (g->map.content[y][x - 1] == '0' || g->map.content[y][x - 1] == 'P')
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->floor_xpm, x * IMG_WIDTH, y * IMG_HEIGHT);
		g->ghost.x--;
		render_ghost(g, g->ghost.x, g->ghost.y);
		return (1);
	}
	return (0);
}
