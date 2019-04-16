/*
** EPITECH PROJECT, 2018
** defender
** File description:
** projectile movement
*/

#include "defender.h"

void move_projectile(projectile_t *projectile)
{
    sfVector2f movement;
    sfTime time = sfClock_getElapsedTime(projectile->clock);
    float sec = time.microseconds / 1000000.0;

    if (sec < 0.001) {
        if (projectile->next != NULL)
            move_projectile(projectile->next);
        return;
    }
    movement.x = projectile->target.x * 0.05;
    movement.y = projectile->target.y * 0.05;
    sfSprite_move(projectile->visual->sprite, movement);
    projectile->visual->position = get_position(projectile->visual->sprite);
    sfClock_restart(projectile->clock);
    projectile->restart++;
    if (projectile->next != NULL)
        move_projectile(projectile->next);
}

void tower_projectile_movement(space_t *tower)
{
    for (space_t * tmp = tower; tmp != NULL; tmp = tmp->next) {
        if (tmp->buildon == 1 && tmp->projectile != NULL) {
            move_projectile(tmp->projectile);
        }
    }
}

projectile_t *stop_projectile(projectile_t *projectile, int type,
    enemy_wave_t *waves)
{
    projectile_t *save = projectile->next;

    if (projectile->restart == 20) {
        apply_arty_dmg_list(projectile, waves, type);
        free_projectile(projectile);
        return (save);
    }
    return (projectile);
}

void tower_projectile_stop(space_t *tower, enemy_wave_t *waves)
{
    for (space_t * tmp = tower; tmp != NULL; tmp = tmp->next) {
        if (tmp->buildon == 1 && tmp->projectile != NULL) {
            tmp->projectile = stop_projectile(tmp->projectile,
                tmp->towertype, waves);
        }
    }
}