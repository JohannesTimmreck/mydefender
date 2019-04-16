/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** create_button
*/

#include "defender.h"

void set_button_visuals(int type, visual_t *visual)
{
    int position = ((type - 1) * 60);

    visual->animrect = create_rect(0, position, 60, 60);
    return;
}

visual_t *create_button_visual(int type, sfVector2f position)
{
    visual_t *visual = malloc(sizeof(visual_t));
    sfVector2f size;

    visual->position = position;
    visual->sprite = sfSprite_create();
    set_button_visuals(type, visual);
    visual->texture = sfTexture_createFromFile(BUILDOPTIONS, NULL);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setTextureRect(visual->sprite, visual->animrect);
    size = create_vector(visual->animrect.width, visual->animrect.height);
    sfSprite_setPosition(visual->sprite, visual->position);
    visual->hitbox = create_intrect(visual->position, size);
    return (visual);
}

button_t *add_to_last_button(button_t *list, button_t *next)
{
    button_t *tmp = list;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = next;
    return (list);
}

button_t *create_button(int type, sfVector2f vector)
{
    button_t *button = malloc(sizeof(button_t));
    button->type = type;
    button->hover = sfFalse;
    button->next = NULL;
    button->visual = create_button_visual(type, vector);
    return (button);
}