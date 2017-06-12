NAME= lem-in

CC= gcc

FLAGS= -Wall -Wextra -Werror

LIBFT= libft.a

SRCS= sources/le_main \
	sources/parse \
	sources/error \
	sources/graph \
	sources/output \
	sources/debug \
	sources/path \
	sources/pathfinding \
	sources/minimum_heap \
	sources/heap_functions \
	sources/ants \
	sources/ant_routing \
	sources/graph_utility \

CFILES= $(addsuffix .c, $(SRCS))

.PHONY: make all re clean fclean

all: $(NAME)

$(NAME): $(CFILES) $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(CFILES) $(LIBFT)

$(LIBFT):
	make -C libft
	mv libft/$(LIBFT) .

clean:
	make clean -C libft
	rm -rf $(LIBFT)

fclean: clean
	rm -rf $(NAME)

re: fclean all