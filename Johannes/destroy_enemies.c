/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** destroy_enemies
*/

#include "defender.h"

void destroy_wave(enemy_wave_t *wave)
{
    enemy_t *tmp = wave->enemy_list->next;

    for (enemy_t *enemy = wave->enemy_list; enemy != NULL; enemy = tmp) {
        sfSprite_destroy(enemy->vs->sprite);
        sfTexture_destroy(enemy->vs->texture);
        free(enemy->vs);
        sfSprite_destroy(enemy->hb->curr->sprite);
        sfTexture_destroy(enemy->hb->curr->texture);
        free(enemy->hb->curr);
        sfSprite_destroy(enemy->hb->empty->sprite);
        sfTexture_destroy(enemy->hb->empty->texture);
        free(enemy->hb->empty);
        free(enemy->hb);
        free(enemy->stats);
        tmp = enemy->next;
        free(enemy);
    }
    free(wave);
}

void destroy_enemy_info(enemy_info_t *info)
{
    enemy_wave_t *tmp = info->enemy_waves->next;

    sfClock_destroy(info->anim_clock);
    sfClock_destroy(info->movement_clock);
    sfClock_destroy(info->spawn_clock);
    for (enemy_wave_t *wave = info->enemy_waves; wave != NULL; wave = tmp) {
        tmp = wave->next;
        destroy_wave(wave);
    }
}