/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** manage_events
*/

#include "defender.h"

void put_space_into_hover(sfMouseMoveEvent m, button_t *t, sfMusic *music)
{
    if (sfIntRect_contains(&t->visual->hitbox, m.x, m.y) == sfTrue
        && t->visual->animrect.top == 0) {
        t->visual->animrect.top = t->visual->animrect.top + 100;
        t->hover = sfTrue;
        sfMusic_play(music);
    } else if (sfIntRect_contains(&t->visual->hitbox, m.x, m.y) == sfFalse) {
        t->visual->animrect.top = 0;
        t->hover = sfFalse;
    }
}