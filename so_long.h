/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:31:54 by skarim            #+#    #+#             */
/*   Updated: 2024/01/19 12:51:48 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# define BUFFER_SIZE 10

# define IMG_HEIGHT 50
# define IMG_WIDTH 50

# define WINDOW_HEIGHT 8200
# define WINDOW_WIDTH  8200

# define GHOST_TIME 7000

typedef struct ghost
{
	int		x;
	int		y;
	int		spawned;
	int		time;
	char	*direction;
}	t_ghost;

typedef struct map
{
	char	**content;
	int		width;
	int		height;
	int		coins;
	int		exit;
	int		player;
	int		ghost;
	int		valid_path;
}	t_map;

typedef struct player
{
	int		x;
	int		y;
	char	*direction;
	int		mv_nbr;
}	t_player;

typedef struct game
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*floor_xpm;
	void		*wall_xpm;
	void		*coin_xpm;
	void		*exit_xpm;
	void		*ghost_right_xpm;
	void		*ghost_left_xpm;
	void		*pac_man_do_xpm;
	void		*pac_man_lo_xpm;
	void		*pac_man_ro_xpm;
	void		*pac_man_uo_xpm;
	t_map		map;
	t_player	player;
	t_ghost		ghost;
}	t_game;

int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar(char c);
void	ft_putnbr(int n);
char	*ft_strdup(char *s1);
void	ft_fail_map(int fd, char *str);
void	ft_error_msg(char *msg);
void	ft_free_map(t_game *g);
void	ft_maperror(t_game *g, char *str);
void	ft_getmap(char **argv, t_game *g);
char	**ft_split(char *s, char c, int fd);
void	ft_map_dimensions(t_game *g);
void	check_ghost_patrol(t_game *g);
void	ft_checkmap(t_game *g);
void	ft_check_path(t_game *g);
void	ft_check_size(t_game *g);
void	prepare_xpm(t_game *g);
void	ft_load_xpm_images(t_game *g);
void	ft_free_xpms(t_game *g);
void	ft_put_image_to_window(t_game *g, void *xpm, int j, int i);
void	ft_rendermap(t_game *g);
int		ft_move_player(int keycode, t_game *g);
int		ft_destroy_notify(t_game *g);
void	ft_free_game(t_game *g);
int		ghost_animation(t_game *g);
void	render_ghost(t_game *g, int x, int y);
void	ft_init_ghost(t_game *g);
int		move_ghost_right(t_game *g, int x, int y);
int		move_ghost_left(t_game *g, int x, int y);
void	ft_put_moves(t_game *g);

#endif