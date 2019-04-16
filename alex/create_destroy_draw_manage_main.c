/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** johannes utils
*/

#include "defender.h"

gp_t *create_gameloop(map_t *map, enemy_info_t *enemy_info)
{
    gp_t *gp = malloc(sizeof(gp_t));
    sfVector2f pos = create_vector(1600, 50);

    gp->font = sfFont_createFromFile(FONT);
    gp->amount = create_text(sfYellow, 35, pos, gp->font);
    gp->value = 1200;
    gp->space = create_buildspace(map->map);
    gp->event = malloc(sizeof(sfEvent));
    gp->music = create_sound(GAME_SOUND, 20, sfTrue);
    sfMusic_play(gp->music);
    start_enemies(enemy_info, map);
    return (gp);
}

void destroy_mainloop(gp_t *gp)
{
    sfText_destroy(gp->amount);
    sfFont_destroy(gp->font);
    free(gp->event);
    destroy_buildspace(gp->space);
    sfMusic_destroy(gp->music);
    free(gp);
}

void draw_main_loop(sfRenderWindow *window, enemy_info_t *enemy_info,
    space_t *space, map_t *map)
{
    sfRenderWindow_clear(window, sfBlack);
    draw_map(map, window);
    draw_waves(window, enemy_info->enemy_waves);
    display_buildspaces(window, space);
}

void manage_mainloop(sfRenderWindow *window, enemy_info_t *enemy_info,
    map_t *map, gp_t *gp)
{
    char *one = "GOLD:";

    manange_waves(enemy_info, map, &gp->value);
    tower_aim(gp->space, enemy_info->enemy_waves);
    tower_projectile_stop(gp->space, enemy_info->enemy_waves);
    tower_projectile_movement(gp->space);
    animate_tower(gp->space);
    one = combine_strings(one, my_int_to_str(gp->value));
    sfText_setString(gp->amount, one);
    draw_main_loop(window, enemy_info, gp->space, map);
    free (one);
}

int check_for_player_exit(sfRenderWindow *window, gp_t *g)
{
    if (sfRenderWindow_isOpen(window) == sfFalse) {
        destroy_mainloop(g);
        return (1);
    }
    if (g->value == -1) {
        destroy_mainloop(g);
        return (2);
    }
    return (0);
}