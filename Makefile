CC = cc
CFLAGS = -Wall -Wextra  -Werror -Ofast
HEADER = cub3d.h
src = main.c helpers/get_next_line.c helpers/get_next_line_utils.c helpers/is_valid_line.c helpers/ft_strrchr.c \
 		helpers/ft_strcmp.c helpers/ft_strtim.c helpers/ft_strncmp.c helpers/ft_atoi.c helpers/ft_memset.c \
		helpers/lst_addback.c helpers/new_item.c map_trim.c fetching_file.c map_validation.c  map_validation_utils.c \
		helpers/ft_strlen.c texture_validation.c helpers/free_env.c validate_scene.c \
		helpers/ft_split.c draw_utils.c draw_utils1.c hooks_handle.c ray_handle.c handle_textures.c \
		player_utils.c wall_utils.c draw_utils2.c

FRAME = MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"


OBG = $(src:.c=.o)
NAME = cub3D


all:$(NAME)

$(NAME) : $(OBG)
	$(CC) $(CFLAGS) $(FRAME) $(OBG) -o $(NAME)

%.o	:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBG)

fclean : clean
	rm -rf $(NAME)

norm :
	norminette ./helpers/*.c *.h *.c

re : fclean all
