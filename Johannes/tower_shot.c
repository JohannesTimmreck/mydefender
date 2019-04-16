/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "defender.h"

float calculate_distance_from_circle(sfVector2f circle_pos,
    sfVector2f enemy_pos)
{
    float distance_x = pow(enemy_pos.x - circle_pos.x, (float)2);
    float distance_y = pow(enemy_pos.y - circle_pos.y, (float)2);
    float distance = distance_x + distance_y;
    return (distance);
}

float get_value(sfVector2f vect)
{
    float value = sqrtf(pow(vect.x, 2) + pow(vect.y, 2));
    return (value);
}

sfBool enemy_in_range(space_t *tower, enemy_t *enemies)
{
    sfVector2f tower_pos = create_vectorf(tower->visual->position.x + 50,
        tower->visual->position.y + 50);
    sfVector2f enemy_pos;
    projectile_t *projectile;
    float distance = 0;

    for (enemy_t *enemy = enemies; enemy != NULL; enemy = enemy->next) {
        enemy_pos = enemy->center_point;
        distance = calculate_distance_from_circle(tower_pos, enemy_pos);
        if (enemy->status != DEAD && enemy->status != DYING
            && distance <= pow(tower->towerstats->range, 2)) {
            projectile = init_projectile(tower->towertype,
                tower_pos, enemy_pos, tower->towerstats->atk);
            sfMusic_play(tower->shoot);
            tower->projectile = add_projectile(tower->projectile, projectile);
            add_single_dmg(tower, &enemy->stats->health);
            return (sfTrue);
        }
    }
    return (sfFalse);
}

void tower_check_waves(space_t *tower, enemy_wave_t *waves)
{
    for (enemy_wave_t *wave = waves; wave != NULL; wave = wave->next) {
        if (wave->spawned == sfTrue && tower->towertype != 4
            && enemy_in_range(tower, wave->enemy_list) == sfTrue) {
            tower->attack = sfTrue;
            tower->atk_ready = sfFalse;
            break;
        } else if (wave->spawned == sfTrue && tower->towertype == 4) {
            slow_wave(tower, wave->enemy_list);
        }
    }
}

void tower_aim(space_t *tower_list, enemy_wave_t *waves)
{
    for (space_t *tower = tower_list; tower != NULL; tower = tower->next) {
        if (tower->buildon == 0)
            continue;
        if (tower->attack == sfFalse && tower->atk_ready == sfTrue)
            tower_check_waves(tower, waves);
    }
}