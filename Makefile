CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCD = mandatory/
SRCF = helper_functions.c ft_split.c get_map.c path_checker.c map_checker.c image_handling.c render_map.c ft_move.c close_game.c so_long.c
gnl_src = get_next_line_folder/get_next_line_utils.c get_next_line_folder/get_next_line.c
SRC = ${addprefix $(SRCD), $(SRCF)} $(gnl_src)
obj = ${SRC:.c=.o}
bnsd = bonus/
bnsf = helper_functions_bonus.c ft_split_bonus.c get_map_bonus.c path_checker_bonus.c map_checker_bonus.c image_handling_bonus.c render_map_bonus.c ft_move_bonus.c close_game_bonus.c ghost_animation_helper_bonus.c ghost_animation_bonus.c display_moves_bonus.c so_long_bonus.c
bns = ${addprefix $(bnsd), $(bnsf)} $(gnl_src)
bns_obj = ${bns:.c=.o}
header = so_long.h
NAME = so_long
bonus_name = so_long_bonus

all: $(NAME)

%.o: %.c $(header)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(obj)
	$(CC) $(obj) -lmlx -framework OpenGL -framework AppKit -o $@

$(bonus_name): $(bns_obj)
	$(CC) $(bns_obj) -lmlx -framework OpenGL -framework AppKit -o $@

bonus: $(bonus_name)

clean:
	rm -rf $(obj)
	rm -rf $(bns_obj)

fclean: clean
	rm -rf $(NAME) $(bonus_name)

re: fclean all