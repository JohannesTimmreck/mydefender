/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** manage_end_menu
*/

#include "defender.h"

int check_end_release(sfMouseButtonEvent m, button_t *options)
{
    button_t *tmp = options;
    int res = 0;

    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
            && tmp->visual->animrect.top == 200) {
            tmp->visual->animrect.top = tmp->visual->animrect.top - 100;
            res = 1;
        }
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
    return (res);
}

int manage_end_input(sfRenderWindow *window, sfEvent *event, end_t *end)
{
    int res = 0;

    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (1);
    }
    if (event->type == sfEvtMouseMoved)
        check_menu_position(event->mouseMove, end->back, end->move);
    if (event->type == sfEvtMouseButtonPressed)
        check_menu_click(event->mouseButton, end->back, end->select);
    if (event->type == sfEvtMouseButtonReleased)
        res = check_end_release(event->mouseButton, end->back);
    return (res);
}