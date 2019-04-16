/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** select_screen_events
*/

#include "defender.h"

void check_select_position(sfMouseMoveEvent m, button_t *options, sfMusic *mus)
{
    button_t *t = options;
    int active = 0;

    while (t != NULL) {
        if (sfIntRect_contains(&t->visual->hitbox, m.x, m.y) == sfTrue
            && t->visual->animrect.top == 0) {
            active = 1;
            sfMusic_play(mus);
        } else if (sfIntRect_contains(&t->visual->hitbox, m.x, m.y) == sfFalse)
            t->visual->animrect.top = 0;
        if (active == 1 && t->type == 1)
            t->visual->animrect.top = t->visual->animrect.top + 100;
        if (active == 1 && t->type > 1)
            t->visual->animrect.top = t->visual->animrect.top + 750;
        active = 0;
        sfSprite_setTextureRect(t->visual->sprite, t->visual->animrect);
        t = t->next;
    }
}

void check_select_click(sfMouseButtonEvent m, button_t *options, sfMusic *musi)
{
    button_t *tmp = options;
    int active = 0;

    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue) {
            active = 1;
            sfMusic_play(musi);
        }
        if (tmp->type == 1 && tmp->visual->animrect.top == 100 && active == 1)
            tmp->visual->animrect.top = tmp->visual->animrect.top + 100;
        if (tmp->type > 1 && tmp->visual->animrect.top == 750 && active == 1)
            tmp->visual->animrect.top = tmp->visual->animrect.top + 750;
        active = 0;
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
}

int release_select_effect(int type)
{
    if (type == 2)
        return (1);
    if (type == 3)
        return (2);
    if (type == 4)
        return (3);
    if (type == 1) {
        return (-2);
    }
    return (0);
}

int check_select_release(sfMouseButtonEvent m, button_t *options)
{
    button_t *tmp = options;
    int res = 1;
    int act = 0;

    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue)
            act = 1;
        if (act == 1 && tmp->type == 1 && tmp->visual->animrect.top == 200) {
            res = release_select_effect(tmp->type);
            tmp->visual->animrect.top = tmp->visual->animrect.top - 100;
        }
        if (act == 1 && tmp->type > 1 && tmp->visual->animrect.top == 1500) {
            res = release_select_effect(tmp->type);
            tmp->visual->animrect.top = tmp->visual->animrect.top - 750;
        }
        act = 0;
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
    return (res);
}

int manage_selection(sfRenderWindow *window, sfEvent *event, select_t *select)
{
    int res = 0;

    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (-1);
    }
    if (event->type == sfEvtMouseMoved)
        check_select_position(event->mouseMove, select->level, select->move);
    if (event->type == sfEvtMouseButtonPressed)
        check_select_click(event->mouseButton, select->level, select->select);
    if (event->type == sfEvtMouseButtonReleased)
        res = check_select_release(event->mouseButton, select->level);
    return (res);
}
