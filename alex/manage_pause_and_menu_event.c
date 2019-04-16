/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** manage_events
*/

#include "defender.h"

void check_menu_position(sfMouseMoveEvent m, button_t *options, sfMusic *music)
{
    button_t *t = options;

    while (t != NULL) {
        put_space_into_hover(m, t, music);
        sfSprite_setTextureRect(t->visual->sprite, t->visual->animrect);
        t = t->next;
    }
}

void check_menu_click(sfMouseButtonEvent m, button_t *options, sfMusic *mu)
{
    button_t *tmp = options;

    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
            && tmp->visual->animrect.top == 100) {
            tmp->visual->animrect.top = tmp->visual->animrect.top + 100;
            sfMusic_play(mu);
        }
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
}

int release_pause_effect(sfRenderWindow *window, int type)
{
    if (type == 1)
        return (2);
    if (type == 2)
        return (3);
    if (type == 3) {
        sfRenderWindow_close(window);
        return (0);
    }
    return (1);
}

int check_pause_release(sfMouseButtonEvent m, button_t *opt, sfRenderWindow *w)
{
    button_t *tmp = opt;
    int res = 1;

    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
            && tmp->visual->animrect.top == 200) {
            tmp->visual->animrect.top = tmp->visual->animrect.top - 100;
            res = release_pause_effect(w, tmp->type);
        }
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
    return (res);
}

int manage_pause_event(sfRenderWindow *window, sfEvent *event, menu_t *pause)
{
    int res = 1;

    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtMouseMoved)
        check_menu_position(event->mouseMove, pause->options, pause->move);
    if (event->type == sfEvtMouseButtonPressed)
        check_menu_click(event->mouseButton, pause->options, pause->select);
    if (event->type == sfEvtMouseButtonReleased)
        res = check_pause_release(event->mouseButton, pause->options, window);
    return (res);
}
