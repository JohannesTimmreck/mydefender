/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** draw enemies in waves
*/

#include "defender.h"

void draw_wave(sfRenderWindow *window, enemy_wave_t *enemies)
{
    for (enemy_t *e = enemies->enemy_list; e != NULL; e = e->next) {
        if (e->status != DEAD) {
            sfRenderWindow_drawSprite(window, e->vs->sprite, NULL);
            sfRenderWindow_drawSprite(window, e->hb->empty->sprite, NULL);
            sfRenderWindow_drawSprite(window, e->hb->curr->sprite, NULL);
        }
    }
}

void draw_waves(sfRenderWindow *window, enemy_wave_t *waves)
{
    for (enemy_wave_t *wave = waves; wave != NULL; wave = wave->next) {
        if (wave->spawned == sfTrue)
            draw_wave(window, wave);
    }
}