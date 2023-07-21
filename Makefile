define convert_to_objs
$(addprefix $(1)/, $(patsubst %.c,%.o,$(notdir $(2))))
endef



CC=cc
CFLAGS=-Wall -Wextra -Werror -fsanitize=address -g3 
RM=rm -rf
NAME=cub3D
LIBFT=-Llibft -lft
UTILS=printerror.c ft_malloc.c strjoin_char.c substr_line.c print_infos.c
PARS = parser.c check_name.c check_infos.c lexer.c textures.c colors.c parse_map.c map_addons.c fill_map.c check_map.c
SRCS=cub3D.c








OBJS = $(call convert_to_objs , sources, $(SRCS)) \
	$(call convert_to_objs , 0.utils, $(UTILS)) \
	$(call convert_to_objs , parsing, $(PARS))

all:libft $(NAME)
	@echo "DONE"
$(NAME):$(OBJS)
	@echo "Cub3D is compiling...."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

libft:
	@$(MAKE) -C libft -s
clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C libft -s fclean
	@echo "clean"
fclean:clean
	@$(RM) $(NAME)
	@echo "fclean"
re:fclean all

.PHONY:all libft clean fclean re

.SILENT:$(OBJS)

