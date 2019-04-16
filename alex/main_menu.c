/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** main_menu
*/

#include "defender.h"

void display_menu_text(sfRenderWindow *window, sfText *text)
{
    sfVector2f pos = create_vector(730, 325);

    sfText_setCharacterSize(text, 35);
    sfText_setPosition(text, pos);
    sfText_setString(text, "START");
    sfRenderWindow_drawText(window, text, NULL);
    pos.y = pos.y + 200;
    sfText_setPosition(text, pos);
    sfText_setString(text, "HOW TO PLAY");
    sfRenderWindow_drawText(window, text, NULL);
    pos.y = pos.y + 200;
    sfText_setPosition(text, pos);
    sfText_setString(text, "EXIT");
    sfRenderWindow_drawText(window, text, NULL);
}

void display_menu(sfRenderWindow *window, menu_t *menu)
{
    button_t *tmp = menu->options;

    sfRenderWindow_drawSprite(window, menu->background->sprite, NULL);
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(window, tmp->visual->sprite, NULL);
        tmp = tmp->next;
    }
    sfText_setCharacterSize(menu->text, 50);
    sfText_setPosition(menu->text, create_vector(680, 150));
    sfText_setString(menu->text, "MY_DEFENDER");
    sfRenderWindow_drawText(window, menu->text, NULL);
    display_menu_text(window, menu->text);
}

int release_main_effect(sfRenderWindow *window, int type)
{
    int selected_map = 0;

    if (type == 1) {
        selected_map = select_map_to_play(window);
        if (selected_map == -2)
            selected_map = 0;
        return (selected_map);
    }
    if (type == 2) {
        how_to_play(window);
        return (0);
    }
    if (type == 3) {
        sfRenderWindow_close(window);
        return (-1);
    }
    return (0);
}

int check_main_release(sfMouseButtonEvent m, button_t *butt, sfRenderWindow *w)
{
    button_t *tmp = butt;
    int res = 0;

    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
            && tmp->visual->animrect.top == 200) {
            tmp->visual->animrect.top = tmp->visual->animrect.top - 100;
            res = release_main_effect(w, tmp->type);
        }
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
    return (res);
}

int manage_main_event(sfRenderWindow *window, sfEvent *event, menu_t *main)
{
    int res = 0;

    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (-1);
    }
    if (event->type == sfEvtMouseMoved)
        check_menu_position(event->mouseMove, main->options, main->move);
    if (event->type == sfEvtMouseButtonPressed)
        check_menu_click(event->mouseButton, main->options, main->select);
    if (event->type == sfEvtMouseButtonReleased)
        res = check_main_release(event->mouseButton, main->options, window);
    return (res);
}