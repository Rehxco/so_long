NAME = so_long

HEADER = so_long.h 

SOURCES = free/free_map.c \
			GNL/get_next_line_utils.c \
			GNL/get_next_line.c \
			parsing/map/playable_map.c \
			parsing/map/read_map.c \
			parsing/map/valid_elements.c \
			parsing/map/valid_map.c \
			parsing/map/valid_walls.c \
			use_minilibx/windows.c \
			main.c \


OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11


RM = rm -f

all: $(MLX) $(NAME)

$(MLX):
	make -C $(MLX_DIR)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(MLX_FLAGS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
