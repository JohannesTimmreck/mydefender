/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** create_main_menu
*/

#include "defender.h"

visual_t *create_menu_background(void)
{
    visual_t *visual = malloc(sizeof(visual_t));

    visual->position = create_vector(0, 0);
    visual->sprite = sfSprite_create();
    visual->texture = sfTexture_createFromFile(MAIN_MENU, NULL);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, visual->position);
    return (visual);
}

menu_t *create_menu(sfFont *font)
{
    menu_t *pause = malloc(sizeof(menu_t));
    sfVector2f pos = create_vector(710, 290);

    pause->text = create_text(sfGreen, 35, pos, font);
    pause->active = 1;
    pause->background = create_menu_background();
    pause->options = create_menu_options(pos);
    pause->select = sfMusic_createFromFile(SELECT_SOUND);
    pause->move = sfMusic_createFromFile(MOVE_SOUND);
    sfMusic_setVolume(pause->select, 20);
    sfMusic_setVolume(pause->move, 20);
    return (pause);
}

int create_main_menu(sfRenderWindow *window)
{
    sfEvent *event = malloc(sizeof(sfEvent));
    sfFont *font = sfFont_createFromFile(FONT);
    menu_t *menu = create_menu(font);
    int leave = 0;

    while (leave == 0 && sfRenderWindow_isOpen(window) == sfTrue) {
        display_menu(window, menu);
        if (sfRenderWindow_pollEvent(window, event) == sfTrue)
            leave = manage_main_event(window, event, menu);
        sfRenderWindow_display(window);
    }
    free (event);
    destroy_menu(menu, 0);
    sfFont_destroy(font);
    return (leave);
}