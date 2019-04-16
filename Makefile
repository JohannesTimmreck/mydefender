##
## EPITECH PROJECT, 2018
## my defender
## File description:
## Makefile
##

SRC	=	./Johannes/tower_shot.c	\
		./Johannes/rect.c	\
		./Johannes/tiles.c \
		./Johannes/load_map.c  \
		./Johannes/split_str.c	\
		./Johannes/create_sound.c	\
		./Johannes/tower_damage.c	\
		./Johannes/projectile_movement.c	\
		./Johannes/projectile.c	\
		./Johannes/enemy_view.c	\
		./Johannes/start_wave.c	\
		./Johannes/draw_waves.c	\
		./Johannes/start_tile.c	\
		./Johannes/move_waves.c	\
		./Johannes/load_waves.c    \
		./Johannes/view_utilis.c	\
		./Johannes/load_enemies.c  \
		./Johannes/map_start_pos.c	\
		./Johannes/johannes_utils.c    \
		./Johannes/enemy_animation.c	\
		./Johannes/attack_animation.c	\
		./Johannes/load_enemy_visual.c \
		./Johannes/get_nbr_from_string.c   \
		./Johannes/castle.c \
		./Johannes/enemy_handling.c \
		./Johannes/handle_healthbar.c \
		./Johannes/map_path_error.c \
		./Johannes/create_tile.c \
		./Johannes/check_enemies_alive.c	\
		./Johannes/destroy_enemies.c	\
		./alex/create_destroy_draw_manage_main.c \
		./alex/main.c \
		./alex/create_window.c \
		./alex/combine_strings.c \
		./alex/create_button.c \
		./alex/create_buildoptions.c \
		./alex/create_buildspace.c \
		./alex/create_buildspace_list.c \
		./alex/create_info_text.c \
		./alex/assign_info_text.c \
		./alex/display_button_and_spaces.c \
		./alex/how_to_play.c \
		./alex/display_how_to.c \
		./alex/create_main_menu.c \
		./alex/main_menu.c \
		./alex/manage_gold.c \
		./alex/my_int_to_str.c \
		./alex/create_pause.c \
		./alex/pause_menu.c \
		./alex/manage_pause_and_menu_event.c \
		./alex/put_space_into_hover.c \
		./alex/player_management.c \
		./alex/space_management.c \
		./alex/button_management.c \
		./alex/build_tower.c \
		./alex/upgrade_or_sell_tower.c \
		./alex/animate_tower.c \
		./alex/create_end_menu.c \
		./alex/end_menu.c \
		./alex/manage_end_menu_event.c \
		./alex/create_selection.c \
		./alex/select_map_to_play.c \
		./alex/manage_selection_event.c \
		./alex/destroy_towers.c \
		./alex/destroy_menus.c \
		./alex/check_for_end.c \
		./alex/manage_highscore.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

CC	=	gcc

CFLAGS	+=	-g -W -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system -l csfml-audio -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all