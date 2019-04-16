/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** move enemies in waves
*/

#include "defender.h"

sfVector2f set_movement_offset(int direction, float speed)
{
    sfVector2f offset;

    switch (direction) {
        case UP:
            offset = create_vectorf(0, -1 * speed);
            break;
        case LEFT:
            offset = create_vectorf((-1) * speed, 0);
            break;
        case DOWN:
            offset = create_vectorf(0, speed);
            break;
        case RIGHT:
            offset = create_vectorf(speed, 0);
    }
    return (offset);
}

sfVector2f get_position(sfSprite *sprite)
{
    return (sfSprite_getPosition(sprite));
}

void move_enemy_in_direction(enemy_t *e)
{
    sfVector2f offset;

    if (e->status == WALKING) {
        offset =  set_movement_offset(e->direction, e->stats->speed);
        sfSprite_move(e->vs->sprite, offset);
        e->vs->position = sfSprite_getPosition(e->vs->sprite);
        sfSprite_move(e->hb->curr->sprite, offset);
        e->hb->curr->position = get_position(e->hb->curr->sprite);
        sfSprite_move(e->hb->empty->sprite, offset);
        e->hb->empty->position = sfSprite_getPosition(e->hb->empty->sprite);
        e->center_point.x += offset.x;
        e->center_point.y += offset.y;
    }
}

void move_enemy_waves(enemy_t *enemies, sfClock *movement_clock)
{
    sfTime move_time = sfClock_getElapsedTime(movement_clock);
    float sec = move_time.microseconds / 1000000.0;

    if (sec < 0.02)
        return;
    for (enemy_t *tmp = enemies; tmp != NULL; tmp = tmp->next)
            move_enemy_in_direction(tmp);
}