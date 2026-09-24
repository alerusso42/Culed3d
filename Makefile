# Top level target
NAME     = cub3D
SRC_PATH = srcs/

# Compiler settings (lm == math.h)
CC       = cc
CFLAGS   = -Wall -Werror -Wextra -g
LFLAGS   =  -I./libft -Lminilibx-linux -lmlx -lX11 -lm -lXext
DEBUG    = -D DEBUG=true
NORMAL   = -D DEBUG=false

# Library 
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a
PARS_DIR  = parsing

# All source files, with their relative paths c
SRCS = $(addprefix $(SRC_PATH), \
	main.c \
	init/mem_handler.c \
	init/entity.c \
	init/get_texture.c \
	init/texture_list.c \
	input/commands.c \
	input/commands2.c \
	input/interact.c \
	input/move.c \
	parsing/parsing.c \
	parsing/get_type.c \
	parsing/get_map.c \
	parsing/check_textures.c \
	parsing/check_map.c \
	parsing/check_map_access.c \
	utils/animation.c \
	utils/bitwise.c \
	utils/debug.c \
	utils/strings.c \
	utils/entity.c \
	utils/error.c \
	utils/time.c \
	utils/math.c \
	utils/minimap.c \
	utils/parsing.c \
	utils/ray_utils.c \
	utils/alloc_utils.c \
	utils/render.c \
	utils/render2.c \
	utils/render3.c \
	utils/texture_filters.c \
	utils/texture_select.c \
	utils/xpm.c \
	render/battle.c \
	render/game_loop.c \
	render/raycast.c \
	render/entity.c \
	render/menu.c \
	sfx/sfx.c \
)
all: $(NAME)

$(NAME): $(LIBFT) $(SRCS) cub3D.h files.h
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(LFLAGS) -o $(NAME)

$(LIBFT): 
	$(MAKE) all -C $(LIBFT_DIR)

gdb: $(NAME)
	gdb -x a.gdb --args ./$(NAME) maps/debug.cub

gdbtui: $(NAME)
	gdb --tui -x a.gdb --args ./$(NAME) maps/debug.cub

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf minilibx-linux

bonus: all

re: fclean mini all

start: fclean mini all

pull: 
	git pull

push: 
	./upd.sh

run:
	clear ; make && ./$(NAME) maps/$(MAP).cub

val: all
	valgrind --suppressions=s.supp --leak-check=full --show-leak-kinds=all --track-origins=yes -s --quiet ./$(NAME) maps/$(MAP).cub

mini: 
	@ls | grep minilibx > /dev/null  && printf "Mini already exists\n" || git clone git@github.com:42paris/minilibx-linux.git > /dev/null ; rm -rf minilibx-linux/.git
	$(MAKE) -C ./minilibx-linux

.PHONY: all bonus clean fclean re libft
.SILENT: