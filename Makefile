# Top level target
NAME     = cub3d
SRC_PATH = srcs/

# Compiler settings (lm == math.h)
CC       = cc
CFLAGS   = -Wall -Werror -Wextra -g
LFLAGS   =  -I./libft -Lminilibx-linux -lXext -lX11 -lmlx -lm

# Library 
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a
PARS_DIR  = parsing

# All source files, with their relative paths c
SRCS = $(addprefix $(SRC_PATH), \
  main.c \
  init/mem_handler.c \
  init/get_texture.c \
  parsing/parsing.c \
  parsing/get_type.c \
  parsing/get_map.c \
  parsing/check_textures.c \
  parsing/check_map.c \
  parsing/check_map_access.c \
  utils/strings.c \
  utils/error.c \
  utils/time.c \
  utils/alloc_utils.c \
  render/test.c \
)
# # Object files go under obj/, mirroring the tree
# OBJ_DIR = obj
# OBJS    = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
all: $(NAME)

$(NAME): $(LIBFT) $(SRCS) cub3d.h
	$(CC) $(CFLAGS) $(SRCS) $(LFLAGS) $(LIBFT) -o $(NAME)

# Build libft (bonus) before anything else
$(LIBFT): 
	$(MAKE) bonus -C $(LIBFT_DIR)

# manca il file a.gdb
gdb: $(NAME)
	gdb -x a.gdb --args ./cub3d debug.cub

gdbtui: $(NAME)
	gdb --tui -x a.gdb --args ./cub3d min.cub

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

re: fclean all

mini: 
	@ls | grep minilibx > /dev/null  && printf "Mini already exists\n" || git clone git@github.com:42paris/minilibx-linux.git > /dev/null ; rm -rf minilibx-linux/.git
	$(MAKE) -C ./minilibx-linux

# phony targets
.PHONY: all clean fclean re libft
# .SILENT: