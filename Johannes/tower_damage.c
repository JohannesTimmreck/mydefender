/*
** EPITECH PROJECT, 2018
** defender
** File description:
** tower damage
*/

#include "defender.h"

void add_single_dmg(space_t *tower, int *enemy_health)
{
    if (tower->towertype == 1 || tower->towertype == 3) {
        *enemy_health -= tower->towerstats->atk;
    }
}

void apply_arty_dmg(projectile_t *projectile, enemy_t *e)
{
    sfVector2f proj_pos = projectile->visual->position;
    float distance = calculate_distance_from_circle(proj_pos, e->center_point);

    if (e->status != DEAD && e->status != DYING && distance <= pow(100, 2))
        e->stats->health -= projectile->damage;
}

void apply_arty_dmg_list(projectile_t *projectile, enemy_wave_t *waves,
    int type)
{
    if (type != 2)
        return;
    for (enemy_wave_t *wave = waves; wave != NULL; wave = wave->next) {
        if (wave->spawned == sfFalse)
            continue;
        for (enemy_t *e = wave->enemy_list; e != NULL; e = e->next)
            apply_arty_dmg(projectile, e);
    }
}

void slow_wave(space_t *tower, enemy_t *enemies)
{
    sfVector2f tower_pos = create_vectorf(tower->visual->position.x + 50,
        tower->visual->position.y + 50);
    sfVector2f enemy_pos;
    float distance = 0;

    for (enemy_t *enemy = enemies; enemy != NULL; enemy = enemy->next) {
        enemy_pos.x = enemy->center_point.x;
        enemy_pos.y = enemy->center_point.y;
        distance = calculate_distance_from_circle(tower_pos, enemy_pos);
        if (enemy->status != DEAD && enemy->status != DYING
            && enemy->slowed == sfFalse
            && distance <= pow(tower->towerstats->range, 2)) {
            enemy->stats->speed *= (float)50/(float)100;
            enemy->slowed = sfTrue;
        }
    }
}