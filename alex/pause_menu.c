/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** johannes utils
*/

#include "defender.h"

void display_pause_text(sfRenderWindow *window, sfText *text)
{
    sfVector2f pos = create_vector(730, 325);

    sfText_setPosition(text, pos);
    sfText_setString(text, "CONTINUE");
    sfRenderWindow_drawText(window, text, NULL);
    pos.y = pos.y + 200;
    sfText_setPosition(text, pos);
    sfText_setString(text, "BACK TO MENU");
    sfRenderWindow_drawText(window, text, NULL);
    pos.y = pos.y + 200;
    sfText_setPosition(text, pos);
    sfText_setString(text, "EXIT");
    sfRenderWindow_drawText(window, text, NULL);
}

void display_pause(sfRenderWindow *window, menu_t *pause)
{
    button_t *tmp = pause->options;

    sfRenderWindow_drawRectangleShape(window, pause->rect, NULL);
    sfRenderWindow_drawSprite(window, pause->background->sprite, NULL);

    while (tmp != NULL) {
        sfRenderWindow_drawSprite(window, tmp->visual->sprite, NULL);
        tmp = tmp->next;
    }
    display_pause_text(window, pause->text);
}

int do_a_pause(sfRenderWindow *window)
{
    sfEvent *event = malloc(sizeof(sfEvent));
    sfFont *font = sfFont_createFromFile(FONT);
    menu_t *pause = create_pause(font);
    int res = 0;

    while (pause->active == 1 && sfRenderWindow_isOpen(window) == sfTrue) {
        while (sfRenderWindow_pollEvent(window, event) == sfTrue)
            pause->active = manage_pause_event(window, event, pause);
        display_pause(window, pause);
        sfRenderWindow_display(window);
    }
    res = pause->active;
    free (event);
    destroy_menu(pause, 1);
    sfFont_destroy(font);
    return (res);
}