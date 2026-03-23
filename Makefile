CC      := cc
CFLAGS  := -Wall -Wextra -Werror

MLX_DIR := minilibx-linux
MLX_REPO := https://github.com/42paris/minilibx-linux.git
MLX_LIB := $(MLX_DIR)/libmlx.a

MLX_LIBS      := $(MLX_LIB) -lXext -lX11 -lm
MAND_INCLUDES := -I$(MLX_DIR) -Imand/include
BONUS_INCLUDES := -I$(MLX_DIR) -Ibonus/include

NAME   := so_long
MAND_TARGET := mand/$(NAME)
MAND_OBJS   := \
    mand/src/main.o \
    mand/src/gnl/get_next_line.o \
    mand/src/gnl/get_next_line_utils.o \
    mand/src/printf/ft_printf.o \
    mand/src/printf/ft_print_nums.o \
    mand/src/printf/ft_print_text.o \
    mand/src/printf/ft_print_pointer.o \
    mand/src/utils/destory.o \
    mand/src/utils/helpers.o \
    mand/src/map/map_exist.o \
    mand/src/events/move_player.o \
    mand/src/rendering/open_run_window.o \
    mand/src/map/read_map.o \
    mand/src/rendering/start_game.o \
    mand/src/map/valid_map_path.o \
    mand/src/map/valid_map.o \
    mand/src/utils/ft_strlen.o \
    mand/src/utils/ft_strncmp.o \
    mand/src/utils/ft_memcpy.o \
    mand/src/rendering/put.o \
    mand/src/map/map_dim.o \
    mand/src/utils/ft_memset.o

BONUS_NAME   := so_long
BONUS_TARGET := bonus/$(BONUS_NAME)
BONUS_OBJS   := \
    bonus/src/main.o \
    bonus/src/gnl/get_next_line.o \
    bonus/src/gnl/get_next_line_utils.o \
    bonus/src/printf/ft_printf.o \
    bonus/src/printf/ft_print_nums.o \
    bonus/src/printf/ft_print_text.o \
    bonus/src/printf/ft_print_pointer.o \
    bonus/src/utils/destory.o \
    bonus/src/utils/helpers.o \
    bonus/src/map/map_exist.o \
    bonus/src/events/move_player.o \
    bonus/src/rendering/open_run_window.o \
    bonus/src/map/read_map.o \
    bonus/src/rendering/start_game.o \
    bonus/src/map/valid_map_path.o \
    bonus/src/map/valid_map.o \
    bonus/src/utils/ft_strlen.o \
    bonus/src/utils/ft_strncmp.o \
    bonus/src/utils/ft_memcpy.o \
    bonus/src/animations/player_anim.o \
    bonus/src/utils/ft_itoa.o \
    bonus/src/enemies/enempy_patrol.o \
    bonus/src/rendering/put.o \
    bonus/src/animations/set_player_anim.o \
    bonus/src/map/map_dim.o \
    bonus/src/utils/ft_memset.o

all: name

name: $(MAND_TARGET)
bonus: $(BONUS_TARGET)

$(MLX_DIR):
	git clone $(MLX_REPO) $(MLX_DIR)

$(MLX_LIB): $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

mand/src/%.o: mand/src/%.c
	$(CC) $(CFLAGS) $(MAND_INCLUDES) -c $< -o $@

bonus/src/%.o: bonus/src/%.c
	$(CC) $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

$(MAND_TARGET): $(MLX_LIB) $(MAND_OBJS)
	$(CC) $(CFLAGS) $(MAND_INCLUDES) $(MAND_OBJS) $(MLX_LIBS) -o $@

$(BONUS_TARGET): $(MLX_LIB) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_INCLUDES) $(BONUS_OBJS) $(MLX_LIBS) -o $@

clean:
	rm -f $(MAND_OBJS) $(BONUS_OBJS)
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean; fi

fclean: clean
	rm -f $(MAND_TARGET) $(BONUS_TARGET)

re: fclean all

.PHONY: all name bonus clean fclean re
