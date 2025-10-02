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

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
