/*
** EPITECH PROJECT, 2018
** defender
** File description:
** animation
*/

#include "defender.h"

void change_animation_direction(enemy_t *enemy)
{
    switch (enemy->direction) {
        case UP:
            enemy->vs->animrect.top = ENEMY_FACE_U;
            break;
        case LEFT:
            enemy->vs->animrect.top = ENEMY_FACE_L;
            break;
        case DOWN:
            enemy->vs->animrect.top = ENEMY_FACE_D;
            break;
        case RIGHT:
            enemy->vs->animrect.top = ENEMY_FACE_R;
    }
    sfSprite_setTextureRect(enemy->vs->sprite, enemy->vs->animrect);
}

void walking_animation(enemy_t *enemy)
{
    if (enemy->anim_sprite == WALK_SPRITES) {
        enemy->vs->animrect.left = 100;
        enemy->anim_sprite = 0;
    } else
        move_rect(&enemy->vs->animrect, create_vectorf(100, 0));
}

void animate_enemy(enemy_t *enemy)
{
    switch (enemy->status) {
        case WALKING:
            walking_animation(enemy);
            break;
        case ATTACKING:
            attacking_animation(enemy);
            break;
        case DYING:
            if (enemy->anim_sprite == DYING_SPRITES)
                enemy->status = DEAD;
            else
                move_rect(&enemy->vs->animrect, create_vectorf(100, 0));
    }
}

void animate_enemies(enemy_t *enemies, sfClock *anim_clock)
{
    sfTime anim_time = sfClock_getElapsedTime(anim_clock);
    float sec = anim_time.microseconds / 1000000.0;

    if (sec < 0.15)
        return;
    for (enemy_t *tmp = enemies; tmp != NULL; tmp = tmp->next) {
        if (tmp->status != DEAD && tmp->status != WAITING) {
            animate_enemy(tmp);
            sfSprite_setTextureRect(tmp->vs->sprite, tmp->vs->animrect);
            tmp->anim_sprite += 1;
        }
    }
}