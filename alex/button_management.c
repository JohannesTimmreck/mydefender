/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** button_management
*/

#include "defender.h"

void check_button_positon(sfMouseMoveEvent m, button_t *options)
{
    button_t *tm = options;

    while (tm != NULL) {
        if (sfIntRect_contains(&tm->visual->hitbox, m.x, m.y) == sfTrue
            && tm->visual->animrect.top == 0) {
            tm->visual->animrect.top = tm->visual->animrect.top + ICONOFFSET;
            tm->hover = sfTrue;
        }
        else if (sfIntRect_contains(&tm->visual->hitbox, m.x, m.y) == sfFalse) {
            tm->visual->animrect.top = 0;
            tm->hover = sfFalse;
        }
        sfSprite_setTextureRect(tm->visual->sprite, tm->visual->animrect);
        tm = tm->next;
    }
}

void check_click_options_button(sfMouseButtonEvent m, button_t *options)
{
    button_t *tmp = options;

    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
            && tmp->visual->animrect.top == ICONOFFSET) {
            tmp->visual->animrect.top = tmp->visual->animrect.top + ICONOFFSET;
        }
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
}

int test_for_valid_click(sfMouseButtonEvent m, space_t *s)
{
    if (s->buildon == 0) {
        if (sfIntRect_contains(&s->buildwheel->hitbox, m.x, m.y) == sfFalse) {
            s->options_active = sfFalse;
            return (1);
        }
    }
    if (s->buildon == 1) {
        if (sfIntRect_contains(&s->upgradewheel->hitbox, m.x, m.y) == sfFalse) {
            s->options_active = sfFalse;
            return (1);
        }
    }
    return (0);
}

int check_button_release(sfMouseButtonEvent m, button_t *b, space_t *s, int gp)
{
    button_t *tmp = b;

    if (test_for_valid_click(m, s) == 1)
        return (gp);
    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
            && tmp->visual->animrect.top == 120) {
            tmp->visual->animrect.top = 0;
            s->options_active = sfFalse;
            gp = upddate_player_money(gp, s, tmp);
        }
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
    return (gp);
}

void release_button_effect(space_t *space, button_t *clicked)
{
    if (clicked->type == 5 || clicked->type < 1)
        return;
    if (clicked->type > 0 && clicked->type < 5) {
        space->buildon = 1;
        space->level = 1;
        space->towertype = clicked->type;
        space->towerstats = assign_stats(clicked->type);
    }
    if (clicked->type == 6)
        sell_tower(space);
    if (clicked->type == 7 && space->level == 2)
        upgrade_tier_two(space);
    if (clicked->type == 7 && space->level == 1)
        upgrade_tier_one(space);
    if (clicked->type < 5 || clicked->type == 6)
        assign_sprite(space, clicked->type);
    assign_sound(space, clicked->type);
}