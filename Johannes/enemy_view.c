/*
** EPITECH PROJECT, 2018
** defender
** File description:
** enemy_view
*/

#include "defender.h"

void check_corner_direction(enemy_t *enemy, tiles_t *tile_list)
{
    switch (enemy->direction) {
        case UP:
            if (check_tile(enemy, tile_list, RIGHT) == sfFalse)
                check_tile(enemy, tile_list, LEFT);
            break;
        case LEFT:
            if (check_tile(enemy, tile_list, UP) == sfFalse)
                check_tile(enemy, tile_list, DOWN);
            break;
        case DOWN:
            if (check_tile(enemy, tile_list, LEFT) == sfFalse)
                check_tile(enemy, tile_list, RIGHT);
            break;
        case RIGHT:
            if (check_tile(enemy, tile_list, DOWN) == sfFalse)
                check_tile(enemy, tile_list, UP);
            break;
    }
}

void enemy_check_for_corner(enemy_t *enemy, tiles_t *tile_list)
{
    sfVector2f v = get_view(enemy->center_point, enemy->direction);

    for (tiles_t *tmp = tile_list; tmp != NULL; tmp = tmp->next) {
        if (sfIntRect_contains(&tmp->visual->hitbox, v.x, v.y) == sfTrue
            && tmp->type != 'P')
            check_corner_direction(enemy, tile_list);
        else if (sfIntRect_contains(&tmp->visual->hitbox, v.x, v.y) == sfTrue)
            break;
    }
}

void enemy_check_for_wall(enemy_t *enemy, tiles_t *tile_list)
{
    sfVector2f v = get_view(enemy->center_point, enemy->direction);

    for (tiles_t *t = tile_list; t != NULL; t = t->next) {
        if (sfIntRect_contains(&t->visual->hitbox, v.x, v.y) == sfTrue
            && t->type == 'G') {
            enemy->status = ATTACKING;
            set_attack_animtaion(enemy);
        } else if (sfIntRect_contains(&t->visual->hitbox, v.x, v.y) == sfTrue)
            break;
    }
}

void enemy_list_change_movement(enemy_t *wave, tiles_t *tile_list)
{
    for (enemy_t *enemy = wave; enemy != NULL; enemy = enemy->next) {
        if (enemy->status == WALKING) {
            enemy_check_for_corner(enemy, tile_list);
            enemy_check_for_wall(enemy, tile_list);
        }
    }
}