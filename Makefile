# Top level target
NAME     = cub3d
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
  init/get_texture.c \
  input/commands.c \
  input/init_entity.c \
  input/move.c \
  parsing/parsing.c \
  parsing/get_type.c \
  parsing/get_map.c \
  parsing/check_textures.c \
  parsing/check_map.c \
  parsing/check_map_access.c \
  utils/strings.c \
  utils/error.c \
  utils/time.c \
  utils/math.c \
  utils/ray_utils.c \
  utils/alloc_utils.c \
  utils/render_utils.c \
  utils/render_utils2.c \
  render/game_loop.c \
  render/raycast.c \
)
all: $(NAME)

$(NAME): $(LIBFT) $(SRCS) cub3d.h
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(LFLAGS) -o $(NAME)

$(LIBFT): 
	$(MAKE) bonus -C $(LIBFT_DIR)

gdb: $(NAME)
	gdb -x a.gdb --args ./cub3d debug.cub

gdbtui: $(NAME)
	gdb --tui -x a.gdb --args ./cub3d debug.cub

val: 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --quiet ./cub3d $(ARG)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf minilibx-linux

bonus: fclean $(NAME)

re: fclean mini all

start: pull fclean mini all

pull: 
	git pull

push: 
	./upd.sh

mini: 
	@ls | grep minilibx > /dev/null  && printf "Mini already exists\n" || git clone git@github.com:42paris/minilibx-linux.git > /dev/null ; rm -rf minilibx-linux/.git
	$(MAKE) -C ./minilibx-linux

.PHONY: all clean fclean re libft
.SILENT: