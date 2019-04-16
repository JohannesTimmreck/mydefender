/*
** EPITECH PROJECT, 2018
** my_defender.c
** File description:
** map_start_pos
*/

#include "defender.h"

sfBool is_path_tile(char c)
{
    switch (c) {
        case 'P':
        case 'R':
        case 'U':
        case 'L':
        case 'D':
            return (sfTrue);
        default:
            return (sfFalse);
    }
}

void det_enemy_start_x(map_t *m)
{
    switch ((int)m->start_position.x) {
        case 0:
            if (is_path_tile(m->map[(int)m->start_position.y][1]) == sfTrue)
                m->start_direction = RIGHT;
            else
                path_error(m, 1);
            break;
        case 19:
            if (is_path_tile(m->map[(int)m->start_position.y][18]) == sfTrue)
                m->start_direction = LEFT;
            else
                path_error(m, 1);
            break;
        default:
            path_error(m, 2);
            break;
    }
}

void det_enemy_start(map_t *m)
{
    switch ((int)m->start_position.y) {
        case 0:
            if (is_path_tile(m->map[1][(int)m->start_position.x]) == sfTrue)
                m->start_direction = DOWN;
            else
                det_enemy_start_x(m);
            break;
        case 10:
            if (is_path_tile(m->map[9][(int)m->start_position.x]) == sfTrue)
                m->start_direction = UP;
            else
                det_enemy_start_x(m);
            break;
        default:
                det_enemy_start_x(m);
            break;
    }
}

void set_enemy_spawn_point(map_t *map)
{
    switch (map->start_direction) {
        case LEFT:
            map->start_position.x = (map->start_position.x + 1) * 100;
            map->start_position.y *= 100;
            break;
        case RIGHT:
            map->start_position.x = (map->start_position.x - 1) * 100;
            map->start_position.y *= 100;
            break;
        case DOWN:
            map->start_position.x *= 100;
            map->start_position.y = (map->start_position.y - 1) * 100;
            break;
        case UP:
            map->start_position.x *= 100;
            map->start_position.y = (map->start_position.y + 1) * 100;
        default:
            break;
    }
}

void get_map_start(map_t *map)
{
    for (tiles_t *tile = map->tile_list; tile != NULL; tile = tile->next) {
        if (tile->type == 'S') {
            map->start_position.x = tile->visual->hitbox.left/100;
            map->start_position.y = tile->visual->hitbox.top/100;
        }
    }
    det_enemy_start(map);
    if (map == NULL)
        return;
    set_enemy_spawn_point(map);
    find_start_tile(map->tile_list, map->start_direction);
}