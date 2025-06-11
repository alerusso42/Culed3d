NAME = libft.a
GNL_PATH = ../getnextline


SRC = 	free_matrix.c    ft_isspace.c     ft_rejoin.c    ft_strlen.c      game_bfs_draw.c \
		ft_atoi.c        ft_itoa.c        ft_rematrix.c  ft_strmapi.c \
		ft_atol.c        ft_memchr.c      ft_restr.c     ft_strncmp_2.c   game_bfs_utils.c \
		ft_bzero.c       ft_memcmp.c      ft_split.c     ft_strncmp.c \
		ft_calloc.c      ft_memcpy.c      ft_strchr.c    ft_strnstr.c \
		ft_dup_matrix.c  ft_memmove.c     ft_strcmp.c    ft_strrchr.c \
		ft_isalnum.c     ft_memset.c      ft_strdup.c    ft_strtrim.c     matrix_len.c \
		ft_isalpha.c     ft_overflow.c    ft_strings.c   ft_substr.c      printf_fd.c \
		ft_isascii.c     ft_putchar_fd.c  ft_striteri.c  ft_tolower.c     printf_light.c \
		ft_isdigit.c     ft_putendl_fd.c  ft_strjoin.c   ft_toupper.c \
		ft_isprint.c     ft_putnbr_fd.c   ft_strlcat.c   game_bfs.c \
		ft_is_quotes.c   ft_putstr_fd.c   ft_strlcpy.c \
		$(GNL_PATH)/get_next_line.c	 $(GNL_PATH)/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUSOBJ = $(BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

bonus: $(OBJ) $(BONUSOBJ)
	ar rcs $(NAME) $(OBJ) $(BONUSOBJ)

.PHONY: all clean fclean re bonus