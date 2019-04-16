/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** johannes utils
*/

#include "defender.h"

int check_for_exit(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtKeyReleased)
        return (1);
    if (event->type == sfEvtMouseButtonReleased)
        return (1);
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (1);
    }
    return (0);
}

void how_to_play(sfRenderWindow *window)
{
    sfEvent *event = malloc(sizeof(sfEvent));
    sfVector2f position = create_vector(950, 150);
    sfFont *font = sfFont_createFromFile(FONT);
    sfText *text = create_text(sfBlack, 10, position, font);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(HOW_TO_PLAY, NULL);
    int leave = 0;

    sfSprite_setTexture(sprite, texture, sfTrue);
    while (leave == 0) {
        sfRenderWindow_drawSprite(window, sprite, NULL);
        display_help(window, text, position);
        while (sfRenderWindow_pollEvent(window, event) == sfTrue)
            leave = check_for_exit(window, event);
        sfRenderWindow_display(window);
    }
    free (event);
    destroy_how_to(font, text, sprite);
    sfTexture_destroy(texture);
}