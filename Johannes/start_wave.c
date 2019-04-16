/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** start wave
*/

#include "defender.h"

void spawn_next_wave(enemy_wave_t *enemy_waves, map_t *map)
{
    for (enemy_wave_t *wave = enemy_waves; wave != NULL; wave = wave->next) {
        if (wave->spawned == sfFalse) {
            spawn_enemies(map->start_position, map->start_direction, wave);
            return;
        }
    }
}

sfIntRect set_start_anim(int direction)
{
    sfVector2f pos = {0, 100};
    sfVector2f size = {100, 100};

    switch (direction) {
        case UP:
            pos.y = ENEMY_FACE_U;
            break;
        case LEFT:
            pos.y = ENEMY_FACE_L;
            break;
        case DOWN:
            pos.y = ENEMY_FACE_D;
            break;
        case RIGHT:
            pos.y = ENEMY_FACE_R;
    }
    return (create_intrect(pos, size));
}

void let_enemy_start(enemy_t *enemies, sfClock *spawn_clock)
{
    sfTime spawm_time = sfClock_getElapsedTime(spawn_clock);
    float sec = spawm_time.microseconds / 1000000.0;
    float enemy_num = 0;

    for (enemy_t *enemy = enemies; enemy != NULL; enemy = enemy->next) {
        if ((enemy->status == WAITING) && (sec > enemy_num * 2))
            enemy->status = WALKING;
        enemy_num += 1;
    }
}

void spawn_enemies(sfVector2f spawn_position, int direction,
    enemy_wave_t *enemies)
{
    enemies->spawned = sfTrue;
    for (enemy_t *x = enemies->enemy_list; x != NULL; x = x->next) {
        sfSprite_setPosition(x->vs->sprite, spawn_position);
        x->vs->position = sfSprite_getPosition(x->vs->sprite);
        x->vs->hitbox.left = spawn_position.x;
        x->vs->hitbox.top = spawn_position.y;
        x->center_point.x = x->vs->position.x + 50;
        x->center_point.y = x->vs->position.y + 50;
        sfSprite_setPosition(x->hb->empty->sprite,
            create_vectorf(x->vs->position.x, x->vs->position.y + 10));
        sfSprite_setPosition(x->hb->curr->sprite,
            create_vectorf(x->vs->position.x + 1, x->vs->position.y + 11));
        x->hb->empty->position = sfSprite_getPosition(x->hb->empty->sprite);
        x->hb->curr->position = sfSprite_getPosition(x->hb->curr->sprite);
        x->direction = direction;
        x->vs->animrect = set_start_anim(direction);
        sfSprite_setTextureRect(x->vs->sprite, x->vs->animrect);
    }
}
