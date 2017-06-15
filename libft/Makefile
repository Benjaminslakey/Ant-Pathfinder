NAME = libft.a

STRINGS= strings/d_strlen \
	strings/dstr_strlen \
	strings/ft_nbrlen \
	strings/ft_str_toupper \
	strings/ft_str_tolower \
	strings/ft_atoi \
	strings/ft_bzero \
	strings/ft_isalnum \
	strings/ft_isalpha \
	strings/ft_isascii \
	strings/ft_isdigit \
	strings/ft_isprint \
	strings/ft_itoa \
	strings/ft_realloc \
	strings/ft_str_isnum \
	strings/ft_strchr \
	strings/ft_strcmp \
	strings/ft_strcpy \
	strings/ft_strdup \
	strings/ft_strndup \
	strings/ft_str_replace \
	strings/ft_strnew \
	strings/ft_strequ \
	strings/ft_strlen \
	strings/ft_strncmp \
	strings/ft_strncpy \
	strings/ft_strnequ \
	strings/ft_strnstr \
	strings/ft_strrchr \
	strings/ft_strsplit \
	strings/ft_strstr \
	strings/ft_strtrim \
	strings/ft_tolower \
	strings/ft_toupper \
	strings/w_dcount \
	strings/ft_strclr \
	strings/ft_strdel \
	strings/ft_striter \
	strings/ft_strsub \
	strings/ft_strjoin \
	strings/ft_strcat \
	strings/ft_strncat \
	strings/ft_strlcat \
	strings/ft_striteri \
	strings/ft_strmap \
	strings/ft_strmapi \
	strings/ft_append_str \
	strings/ft_prepend_str \
	strings/ft_strcspn \
	strings/ft_is_prime \
	strings/ft_sqrt \
	strings/chr_count \

MEMORY= memory/ft_memcpy \
	memory/ft_memccpy \
	memory/ft_memmove \
	memory/ft_memchr \
	memory/ft_memdel \
	memory/ft_memalloc \
	memory/ft_memset \
	memory/ft_memcmp \
	memory/swap_integers \
	memory/free_strings \
	memory/free_int_arrays \

ARRAYS= arrays/new_int_table \
	arrays/delete_int_table \
	arrays/clone_int_array \
	arrays/copy_int_array \
	arrays/array_reverse_int \
	arrays/str_inhaystack \

LISTS= lists/ft_lstnew \
	lists/ft_lstdelone \
	lists/ft_lstdel \
	lists/ft_lstadd \
	lists/ft_lstiter \
	lists/ft_lstmap \

TREES= trees/ft_btree_create_node \
	trees/ft_btree_apply_prefix \
	trees/ft_btree_apply_infix \

SORT= sort/integer_quicksort \

INPUT= input/get_next_line

OUTPUT= output/ft_putchar \
	output/ft_putchar_fd \
	output/ft_putendl \
	output/ft_putendl_fd \
	output/ft_putnbr \
	output/ft_putnbr_fd \
	output/ft_putstr \
	output/ft_putstr_fd \
	output/print_bits \
	output/print_hex \

SRCS= 	$(addprefix srcs/, $(STRINGS) $(MEMORY) $(ARRAYS) $(LISTS) $(TREES) $(SORT) $(INPUT) $(OUTPUT))

CFILES= $(addsuffix .c, $(SRCS))

OFILES= $(addsuffix .o, $(SRCS))

OBJS= $(addsuffix .o, $(notdir $(SRCS)))

HEADER= -I ../libft

CFLAGS= -Wall -Wextra -Werror

.PHONY: make all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

$(OBJ): $(CFILES)
	gcc $(HEADER) $(CFLAGS) $(CFILES) -c

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

