/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** create_pause
*/

#include "defender.h"

visual_t *create_pause_background(void)
{
    visual_t *visual = malloc(sizeof(visual_t));

    visual->position = create_vector(610, 190);
    visual->sprite = sfSprite_create();
    visual->texture = sfTexture_createFromFile(PAUSE_MENU, NULL);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, visual->position);
    return (visual);
}

visual_t *create_menu_button_visual(sfVector2f vector)
{
    visual_t *visual = malloc(sizeof(visual_t));

    visual->position = vector;
    visual->sprite = sfSprite_create();
    visual->animrect = create_rect(0, 0, 100, 500);
    visual->hitbox = create_rect(vector.y, vector.x, 100, 500);
    visual->texture = sfTexture_createFromFile(PAUSE_BUTTON, NULL);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setTextureRect(visual->sprite, visual->animrect);
    sfSprite_setPosition(visual->sprite, vector);
    return (visual);
}

button_t *create_button_menu(int type, sfVector2f vector)
{
    button_t *button = malloc(sizeof(button_t));

    button->type = type;
    button->hover = sfFalse;
    button->next = NULL;
    button->visual = create_menu_button_visual(vector);
    return (button);
}

button_t *create_menu_options(sfVector2f pos)
{
    button_t *options;
    button_t *next;
    int type = 2;

    options = create_button_menu(1, pos);
    while (type != 4) {
        pos.y = pos.y + 200;
        next = create_button_menu(type, pos);
        options = add_to_last_button(options, next);
        type++;
    }
    return (options);
}

menu_t *create_pause(sfFont *font)
{
    menu_t *pause = malloc(sizeof(menu_t));
    sfVector2f pos = create_vector(710, 290);
    sfColor color;

    color = sfColor_fromRGBA(131, 131, 131, 3);
    pause->active = 1;
    pause->text = create_text(sfGreen, 35, pos, font);
    pause->background = create_pause_background();
    pause->options = create_menu_options(pos);
    pause->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(pause->rect, create_vector(0, 0));
    sfRectangleShape_setSize(pause->rect, create_vector(1920, 1080));
    sfRectangleShape_setFillColor(pause->rect, color);
    pause->select = sfMusic_createFromFile(SELECT_SOUND);
    pause->move = sfMusic_createFromFile(MOVE_SOUND);
    sfMusic_setVolume(pause->select, 20);
    sfMusic_setVolume(pause->move, 20);
    return (pause);
}
