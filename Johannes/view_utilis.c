/*
** EPITECH PROJECT, 2018
** defender
** File description:
** view_utilis
*/

#include "defender.h"

sfVector2f get_view(sfVector2f pos, int direction)
{
    sfVector2f view;

    switch (direction) {
        case UP:
            view = create_vectorf(pos.x, pos.y - 51);
            break;
        case LEFT:
            view = create_vectorf(pos.x - 51, pos.y);
            break;
        case DOWN:
            view = create_vectorf(pos.x, pos.y + 51);
            break;
        case RIGHT:
            view = create_vectorf(pos.x + 51, pos.y);
            break;
    }
    return (view);
}

sfBool check_tile(enemy_t *enemy, tiles_t *tile_list, int direction)
{
    sfVector2f view = get_view(enemy->center_point, direction);


    for (tiles_t *tmp = tile_list; tmp != NULL; tmp = tmp->next) {
        if (sfIntRect_contains(&tmp->visual->hitbox, view.x, view.y) == sfTrue
            && tmp->type == 'P') {
            enemy->direction = direction;
            change_animation_direction(enemy);
            return (sfTrue);
        }
    }
    return (sfFalse);
}