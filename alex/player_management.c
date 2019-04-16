/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** johannes utils
*/

#include "defender.h"

int check_for_pause(sfRenderWindow *window, sfKeyEvent key)
{
    int res = 1;

    if (key.code == sfKeyEscape)
        res = do_a_pause(window);
    return (res);
}

int event_management(sfRenderWindow *w, sfEvent *event, space_t *space, int gp)
{
    int res = 1;

    if (event->type == sfEvtClosed)
        sfRenderWindow_close(w);
    if (event->type == sfEvtMouseMoved)
        check_space_position(event->mouseMove, space);
    if (event->type == sfEvtMouseButtonPressed)
        check_click_options_space(event->mouseButton, space);
    if (event->type == sfEvtMouseButtonReleased)
        gp = check_space_release(event->mouseButton, space, gp);
    if (event->type == sfEvtKeyReleased)
        res = check_for_pause(w, event->key);
    if (res == 3)
        return (-1);
    return (gp);
}