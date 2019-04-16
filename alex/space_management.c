/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** space_managemnt
*/

#include "defender.h"

void change_space_rect(sfMouseMoveEvent m, space_t *tmp)
{
    if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
        && tmp->visual->animrect.top == 0)
        tmp->visual->animrect.top = tmp->visual->animrect.top + TOWEROFFSET;
    else if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfFalse)
        tmp->visual->animrect.top = 0;
}

void check_space_position(sfMouseMoveEvent mouse, space_t *space)
{
    space_t *tmp = space;

    while (tmp != NULL) {
        while (tmp != NULL && tmp->options_active == sfTrue
            && tmp->buildon == 1) {
            check_button_positon(mouse, tmp->upgradeoptions);
            tmp = tmp->next;
        }
        while (tmp != NULL && tmp->options_active == sfTrue
            && tmp->buildon == 0) {
            check_button_positon(mouse, tmp->buildoptions);
            tmp = tmp->next;
        }
        if (tmp == NULL)
            return;
        change_space_rect(mouse, tmp);
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
}

void check_click_options_space(sfMouseButtonEvent mouse, space_t *space)
{
    space_t *t = space;

    while (t != NULL) {
        while (t != NULL && t->options_active == sfTrue && t->buildon == 1) {
            check_click_options_button(mouse, t->upgradeoptions);
            t = t->next;
        }
        while (t != NULL && t->options_active == sfTrue && t->buildon == 0) {
            check_click_options_button(mouse, t->buildoptions);
            t = t->next;
        }
        if (t == NULL)
            return;
        if (sfIntRect_contains(&t->visual->hitbox, mouse.x, mouse.y) == sfTrue
            && t->visual->animrect.top == TOWEROFFSET)
            t->visual->animrect.top = t->visual->animrect.top + TOWEROFFSET;
        sfSprite_setTextureRect(t->visual->sprite, t->visual->animrect);
        t = t->next;
    }
}

void check_for_options_active(sfMouseButtonEvent m, space_t *tmp)
{
    if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
        && tmp->visual->animrect.top == 200) {
        tmp->visual->animrect.top = tmp->visual->animrect.top - TOWEROFFSET;
        tmp->options_active = sfTrue;
    }
}

int check_space_release(sfMouseButtonEvent mouse, space_t *space, int gp)
{
    space_t *tmp = space;

    while (tmp != NULL) {
        while (tmp != NULL && tmp->options_active == sfTrue
            && tmp->buildon == 1) {
            gp = check_button_release(mouse, tmp->upgradeoptions, tmp, gp);
            tmp = tmp->next;
        }
        while (tmp != NULL && tmp->options_active == sfTrue
            && tmp->buildon == 0) {
            gp = check_button_release(mouse, tmp->buildoptions, tmp, gp);
            tmp = tmp->next;
        }
        if (tmp == NULL)
            return (gp);
        check_for_options_active(mouse, tmp);
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
    return (gp);
}