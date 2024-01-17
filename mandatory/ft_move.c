/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:41:19 by skarim            #+#    #+#             */
/*   Updated: 2024/01/16 11:10:16 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_left(t_game *g, int x, int y)
{
	g->player.direction = "left";
	if (g->map.content[y][x - 1] != '1')
	{
		if (g->map.content[y][x - 1] == 'E' && g->map.coins != 0)
			return ;
		if (g->map.content[y][x - 1] == 'E' && g->map.coins == 0)
		{
			write(1, "You Won!", 8);
			ft_free_game(g);
		}
		if (g->map.content[y][x - 1] == 'C')
			g->map.coins--;
		g->map.content[y][x] = '0';
		g->map.content[y][x - 1] = 'P';
		ft_put_image_to_window(g, g->floor_xpm, x, y);
		ft_put_image_to_window(g, g->pac_man_lo_xpm, x - 1, y);
		g->player.x -= 1;
		g->player.mv_nbr++;
	}
}

void	ft_move_right(t_game *g, int x, int y)
{
	g->player.direction = "right";
	if (g->map.content[y][x + 1] != '1')
	{
		if (g->map.content[y][x + 1] == 'E' && g->map.coins != 0)
			return ;
		if (g->map.content[y][x + 1] == 'E' && g->map.coins == 0)
		{
			write(1, "You Won!", 8);
			ft_free_game(g);
		}
		if (g->map.content[y][x + 1] == 'C')
			g->map.coins--;
		g->map.content[y][x] = '0';
		g->map.content[y][x + 1] = 'P';
		ft_put_image_to_window(g, g->floor_xpm, x, y);
		ft_put_image_to_window(g, g->pac_man_ro_xpm, x + 1, y);
		g->player.x += 1;
		g->player.mv_nbr++;
	}
}

void	ft_move_up(t_game *g, int x, int y)
{
	g->player.direction = "up";
	if (g->map.content[y - 1][x] != '1')
	{
		if (g->map.content[y - 1][x] == 'E' && g->map.coins != 0)
			return ;
		if (g->map.content[y - 1][x] == 'E' && g->map.coins == 0)
		{
			write(1, "You Won!", 8);
			ft_free_game(g);
		}
		if (g->map.content[y - 1][x] == 'C')
			g->map.coins--;
		g->map.content[y][x] = '0';
		g->map.content[y - 1][x] = 'P';
		ft_put_image_to_window(g, g->floor_xpm, x, y);
		ft_put_image_to_window(g, g->pac_man_uo_xpm, x, y - 1);
		g->player.y -= 1;
		g->player.mv_nbr++;
	}
}

void	ft_move_down(t_game *g, int x, int y)
{
	g->player.direction = "down";
	if (g->map.content[y + 1][x] != '1')
	{
		if (g->map.content[y + 1][x] == 'E' && g->map.coins != 0)
			return ;
		if (g->map.content[y + 1][x] == 'E' && g->map.coins == 0)
		{
			write(1, "You Won!", 8);
			ft_free_game(g);
		}
		if (g->map.content[y + 1][x] == 'C')
			g->map.coins--;
		g->map.content[y][x] = '0';
		g->map.content[y + 1][x] = 'P';
		ft_put_image_to_window(g, g->floor_xpm, x, y);
		ft_put_image_to_window(g, g->pac_man_do_xpm, x, y + 1);
		g->player.y += 1;
		g->player.mv_nbr++;
	}
}

int	ft_move_player(int keycode, t_game *g)
{
	int	x;
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
		ft_free_game(g);
	if (x != g->player.x || y != g->player.y)
		return (ft_putnbr(g->player.mv_nbr), ft_putchar('\n'), 0);
	return (0);
}
