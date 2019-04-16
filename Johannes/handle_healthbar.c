/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "defender.h"

void adjust_healthbar(visual_t *healthbar, int health, int max_health)
{
    float ratio = (float)health/(float)max_health;

    if (health <= 0) {
        sfSprite_setScale(healthbar->sprite, create_vectorf(0, 0));
        return;
    }
    sfSprite_setScale(healthbar->sprite, create_vectorf(1, 1));
    sfSprite_scale(healthbar->sprite, create_vectorf(ratio, 1));
}

void enemies_adjust_health(enemy_t *enemies)
{
    for (enemy_t *tmp = enemies; tmp != NULL; tmp = tmp->next)
        adjust_healthbar(tmp->hb->curr, tmp->stats->health,
            tmp->stats->max_health);
}

sfTexture *set_texture(int txt_num)
{
    char *paths[3] = {LV1_DIE, LV2_DIE, LV3_DIE};

    return (sfTexture_createFromFile(paths[txt_num], NULL));
}

void let_enemies_die(enemy_t *enemies, int *gold)
{

    for (enemy_t *tmp = enemies; tmp != NULL; tmp = tmp->next) {
        if (tmp->stats->health <= 0 && tmp->status != DYING
            && tmp->status != DEAD) {
            *gold += tmp->stats->reward;
            tmp->status = DYING;
            tmp->vs->texture = set_texture(tmp->stats->level - 1);
            tmp->vs->animrect = create_intrect(create_vectorf(0, 0),
                create_vectorf(100, 100));
            sfSprite_setTexture(tmp->vs->sprite, tmp->vs->texture, sfTrue);
            sfSprite_setTextureRect(tmp->vs->sprite, tmp->vs->animrect);
            tmp->anim_sprite = 1;
        }
    }
}

void handle_castle_healthbar(enemy_t *enemies, castle_t *c)
{
    for (enemy_t *tmp = enemies; tmp != NULL; tmp = tmp->next) {
        if (tmp->status == ATTACKING && tmp->anim_sprite == 5
            && tmp->attacked == sfFalse) {
            tmp->attacked = sfTrue;
            c->health -= tmp->stats->dmg;
        }
    }
    adjust_healthbar(c->healthbar->curr, c->health, c->max_health);
}