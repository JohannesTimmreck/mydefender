/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** enemy_attack_animation
*/

#include "defender.h"

void set_attack_animtaion(enemy_t *e)
{
    char *tp[3] = {LV1_ATTACK, LV2_ATTACK, LV3_ATTACK};

    e->anim_sprite = 1;
    e->vs->animrect.left = 0;
    e->vs->texture = sfTexture_createFromFile(tp[e->stats->level - 1], NULL);
    sfSprite_setTexture(e->vs->sprite, e->vs->texture, sfTrue);
    sfSprite_setTextureRect(e->vs->sprite, e->vs->animrect);
}

sfBool check_for_attack_end(enemy_t *enemy)
{
    switch (enemy->stats->level) {
        case 2:
            if (enemy->anim_sprite == ATTACK_LV2_SPRITES)
                return (sfTrue);
            break;
        default:
            if (enemy->anim_sprite == ATTACK_SPRITES)
                return (sfTrue);
    }
    return (sfFalse);
}

void reset_attack_anim(enemy_t *enemy)
{
    switch (enemy->stats->level) {
        case 2:
            enemy->vs->animrect.left = 300;
            enemy->anim_sprite = 3;
            break;
        default:
            enemy->vs->animrect.left = 0;
            enemy->anim_sprite = 0;
    }
    enemy->attacked = sfFalse;
}

void attacking_animation(enemy_t *enemy)
{
    if (enemy->anim_sprite == ATTACK_SPRITES) {
        reset_attack_anim(enemy);
    } else
        move_rect(&enemy->vs->animrect, create_vectorf(100, 0));
}
