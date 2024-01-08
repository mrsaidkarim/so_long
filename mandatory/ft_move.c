/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:48:43 by skarim            #+#    #+#             */
/*   Updated: 2024/01/08 18:57:58 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_left(t_game *g, int x, int y)
{
	g->player.direction = "left";
	ft_rendermap(g);
	if (g->map.content[y][x-1] != '1')
	{
		if (g->map.content[y][x-1] == 'E' && g->map.coins != 0)
			return ;
		if (g->map.content[y][x-1] == 'E' && g->map.coins == 0)
		{
			g->map.content[y][x] = '0';
			ft_maperror(&g, "finished");
		}
		if (g->map.content[y][x-1] == 'C')
			g->map.coins--;
		g->map.content[y][x] = '0';
		g->map.content[y][x-1] = 'P';
		g->player.x -= 1;
		g->player.direction = "left";
		g->player.mv_nbr++;
	}
}

void	ft_move_right(t_game *g, int x, int y)
{
	g->player.direction = "right";
	ft_rendermap(g);
	if (g->map.content[y][x+1] != '1')
	{
		if (g->map.content[y][x+1] == 'E' && g->map.coins != 0)
			return ;
		if (g->map.content[y][x+1] == 'E' && g->map.coins == 0)
		{
			g->map.content[y][x] = '0';
			ft_maperror(&g, "finished");
		}
		if (g->map.content[y][x+1] == 'C')
			g->map.coins--;
		g->map.content[y][x] = '0';
		g->map.content[y][x+1] = 'P';
		g->player.x += 1;
		g->player.direction = "right";
		g->player.mv_nbr++;
	}
}

void	ft_move_up(t_game *g, int x, int y)
{
	g->player.direction = "up";
	ft_rendermap(g);
	if (g->map.content[y-1][x] != '1')
	{
		if (g->map.content[y-1][x] == 'E' && g->map.coins != 0)
			return ;
		if (g->map.content[y-1][x] == 'E' && g->map.coins == 0)
		{
			g->map.content[y][x] = '0';
			ft_maperror(&g, "finished");
		}
		if (g->map.content[y-1][x] == 'C')
			g->map.coins--;
		g->map.content[y][x] = '0';
		g->map.content[y-1][x] = 'P';
		g->player.y -= 1;
		g->player.direction = "up";
		g->player.mv_nbr++;
	}
}

void	ft_move_down(t_game *g, int x, int y)
{
	g->player.direction = "down";
	ft_rendermap(g);
	if (g->map.content[y+1][x] != '1')
	{
		if (g->map.content[y+1][x] == 'E' && g->map.coins != 0)
			return ;
		if (g->map.content[y+1][x] == 'E' && g->map.coins == 0)
		{
			g->map.content[y][x] = '0';
			ft_maperror(&g, "finished");
		}
		if (g->map.content[y+1][x] == 'C')
			g->map.coins--;
		g->map.content[y][x] = '0';
		g->map.content[y+1][x] = 'P';
		g->player.y += 1;
		g->player.direction = "down";
		g->player.mv_nbr++;
	}
}

int	ft_move_player(int keycode, t_game *g)
{
	int x;
	int	y;

	x = g->player.x;
	y = g->player.y;
	if ((keycode == 123 || keycode == 0))
		ft_move_left(g, x, y);
	if ((keycode == 124 || keycode == 2))
		ft_move_right(g, x, y);
	if ((keycode == 126 || keycode == 13))
		ft_move_up(g, x, y);
	if ((keycode == 125 || keycode == 1))
		ft_move_down(g, x, y);
	if (keycode == 53)
	{
		mlx_destroy_window(g->mlx_ptr, g->win_ptr);
		ft_free(&g);
		exit(1);
	}
	ft_rendermap(g);
	ft_putnbr(g->player.mv_nbr);
	return (0);
}