/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** create_select_screen
*/

#include "defender.h"

visual_t *create_select_button_visual(sfVector2f vector)
{
    visual_t *visual = malloc(sizeof(visual_t));

    visual->position = vector;
    visual->sprite = sfSprite_create();
    visual->animrect = create_rect(0, 0, 750, 500);
    visual->hitbox = create_rect(vector.y, vector.x, 750, 500);
    visual->texture = sfTexture_createFromFile(SELECT_BUTTON, NULL);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setTextureRect(visual->sprite, visual->animrect);
    sfSprite_setPosition(visual->sprite, vector);
    return (visual);
}

button_t *create_button_select(int type, sfVector2f vector)
{
    button_t *button = malloc(sizeof(button_t));

    button->type = type;
    button->hover = sfFalse;
    button->next = NULL;
    button->visual = create_select_button_visual(vector);
    return (button);
}

button_t *create_select_button(sfVector2f vector)
{
    button_t *options;
    button_t *next;
    int type = 2;

    options = create_button_menu(1, vector);
    vector = create_vector(105, 25);
    while (type != 5) {
        next = create_button_select(type, vector);
        options = add_to_last_button(options, next);
        vector.x = vector.x + 605;
        type++;
    }
    return (options);
}

void set_level_pictures(select_t *select)
{
    sfVector2f vector;

    vector = create_vector(162, 170);
    select->one = create_visual(LEVEL1, vector);
    vector.x = vector.x + 605;
    select->two = create_visual(LEVEL2, vector);
    vector.x = vector.x + 605;
    select->three = create_visual(LEVEL3, vector);
    vector = create_vector(2, 2);
    sfSprite_setScale(select->one->sprite, vector);
    sfSprite_setScale(select->two->sprite, vector);
    sfSprite_setScale(select->three->sprite, vector);
}

select_t *create_selection(sfFont *font)
{
    select_t *select = malloc(sizeof(select_t));
    sfVector2f vector = create_vector(0, 0);

    select->background = create_visual(SELECT_MENU, vector);
    set_level_pictures(select);
    select->name = create_text(sfYellow, 30, vector, font);
    vector = create_vector(145, 600);
    select->star = create_visual(STAR, vector);
    vector = create_vectorf(0.5, 0.5);
    sfSprite_setScale(select->star->sprite, vector);
    vector = create_vector(710, 800);
    select->level = create_select_button(vector);
    select->select = sfMusic_createFromFile(SELECT_SOUND);
    select->move = sfMusic_createFromFile(MOVE_SOUND);
    sfMusic_setVolume(select->select, 20);
    sfMusic_setVolume(select->move, 20);
    return (select);
}
