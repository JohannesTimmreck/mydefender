/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** enemy_handling
*/

#include "defender.h"

void check_for_clock_restart(enemy_info_t *enemy_info, map_t *map)
{
    sfTime time_check = sfClock_getElapsedTime(enemy_info->anim_clock);
    float sec = time_check.microseconds / 1000000.0;

    if (sec >= 0.15)
        sfClock_restart(enemy_info->anim_clock);
    time_check = sfClock_getElapsedTime(enemy_info->movement_clock);
    sec = time_check.microseconds / 1000000.0;
    if (sec > 0.02)
        sfClock_restart(enemy_info->movement_clock);
    time_check = sfClock_getElapsedTime(enemy_info->spawn_clock);
    sec = time_check.microseconds / 1000000.0;
    if (sec > 30.0) {
        sfClock_restart(enemy_info->spawn_clock);
        spawn_next_wave(enemy_info->enemy_waves, map);
    }
}

enemy_info_t *init_enemy_info(char *path_to_waves)
{
    enemy_info_t *enemy_info = malloc(sizeof(enemy_info_t));

    enemy_info->enemy_waves = load_enemy_waves(path_to_waves);
    return (enemy_info);
}

void manange_waves(enemy_info_t *enemy_info, map_t *map, int *gold)
{
    for (enemy_wave_t *w = enemy_info->enemy_waves; w != NULL; w = w->next) {
        if (w->spawned == sfTrue) {
            let_enemy_start(w->enemy_list, enemy_info->spawn_clock);
            enemies_adjust_health(w->enemy_list);
            let_enemies_die(w->enemy_list, gold);
            enemy_list_change_movement(w->enemy_list, map->tile_list);
            animate_enemies(w->enemy_list, enemy_info->anim_clock);
            move_enemy_waves(w->enemy_list, enemy_info->movement_clock);
            handle_castle_healthbar(w->enemy_list, map->castle);
        }
    }
    check_for_clock_restart(enemy_info, map);
}

void start_enemies(enemy_info_t *enemy_info, map_t *map)
{
    spawn_enemies(map->start_position,
        map->start_direction, enemy_info->enemy_waves);
    enemy_info->movement_clock = sfClock_create();
    enemy_info->anim_clock = sfClock_create();
    enemy_info->spawn_clock = sfClock_create();
}