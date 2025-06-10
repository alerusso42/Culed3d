#–– Top‑level target
NAME     = cub3d

#–– Compiler settings
CC       = cc
CFLAGS   = -g -Wall -Werror -Wextra -I./libft
LDFLAGS  = -lreadline -lhistory -lncurses

#–– Library
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a
PARS_DIR  = parsing

#–– All source files, with their relative paths
SRCS = \
  main.c \

# #–– Object files go under obj/, mirroring the tree
# OBJ_DIR = obj
# OBJS    = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))


all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(LIBFT) $(LDFLAGS) -o $@

#–– Build libft (bonus) before anything else
$(LIBFT): 
	$(MAKE) bonus -C $(LIBFT_DIR)

#–– Single pattern rule for every .c → .o
#––   - mkdir -p $(dir $@) makes sure subdirs exist
# $(OBJ_DIR)/%.o: %.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) -c $< -o $@

# manca il file a.gdb
gdb:
	$(MAKE) gdb -C
	a.gdb ./cub3d

val: 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --quiet ./minishell

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

bonus: fclean $(NAME)

re: fclean all

#–– phony targets
.PHONY: all clean fclean re libft