/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** animated tower
*/

#include "defender.h"

void animate_tower_attack(space_t *towe)
{
    sfTime time = sfClock_getElapsedTime(towe->towerstats->clock);
    float sec = time.microseconds /1000000.0;
    sfVector2f offset = create_vector(100, 0);

    if (sec >= 0.2) {
        move_rect(&towe->visual->animrect, offset);
        if (towe->towertype > 1 && towe->visual->animrect.left == 400) {
            towe->visual->animrect.left = 0;
            towe->attack = sfFalse;
        }
        if (towe->towertype == 1 && towe->visual->animrect.left == 100) {
            towe->visual->animrect.left = 0;
            towe->attack = sfFalse;
        }
        sfSprite_setTextureRect(towe->visual->sprite, towe->visual->animrect);
        sfClock_restart(towe->towerstats->clock);
    }
}

void change_attack_status(space_t *tmp)
{
    sfTime time = sfClock_getElapsedTime(tmp->towerstats->clock);
    float sec = time.microseconds /1000000.0;

    if (tmp->towerstats->spd <= sec) {
        tmp->atk_ready = sfTrue;
        sfClock_restart(tmp->towerstats->clock);
    }
}

void animate_tower(space_t *space)
{
    space_t *tmp = space;

    while (tmp != NULL) {
        while (tmp != NULL && (tmp->buildon == 0
            || tmp->attack == sfTrue || tmp->atk_ready == sfTrue)) {
            if (tmp->attack == sfTrue)
                animate_tower_attack(tmp);
            tmp = tmp->next;
        }
        if (tmp == NULL)
            return;
        change_attack_status(tmp);
        tmp = tmp->next;
    }
}