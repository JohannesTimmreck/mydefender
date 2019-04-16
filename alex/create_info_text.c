/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** create_info_text
*/

#include "defender.h"

sfText *create_text(sfColor color, int size, sfVector2f pos, sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setFillColor(text, color);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    return (text);
}

char *assign_text_upgrade(int type, space_t *space)
{
    char *one = "ERR";
    char *two = "OR";

    if (type == 6) {
        one = "\n\nSELL THIS TOWER AND\nGET A ";
        two = my_int_to_str(space->towerstats->refund);
        one = combine_strings(one, two);
        two = " GP REFUND\n";
        one = combine_strings(one, two);
    }
    if (type == 7) {
        if (space->level == 1)
            one = get_upgrade_1_type(space->towertype);
        if (space->level == 2)
            one = get_upgrade_2_type(space->towertype);
    }
    return (one);
}

void print_info_text(sfRenderWindow *w, button_t *o, sfVector2f p, space_t *s)
{
    sfFont *font = sfFont_createFromFile(FONT);
    sfText *name = create_text(sfYellow, 10, p, font);
    sfText *info = create_text(sfYellow, 7, p, font);

    sfText_setString(name, assign_title(o->type, s));
    if (o->type < 5)
        sfText_setString(info, assign_text_build(o->type));
    if (o->type > 5)
        sfText_setString(info, assign_text_upgrade(o->type, s));
    sfRenderWindow_drawText(w, info, NULL);
    sfRenderWindow_drawText(w, name, NULL);
    sfText_destroy(name);
    sfText_destroy(info);
    sfFont_destroy(font);
}

void display_information(sfRenderWindow *w, button_t *option, space_t *space)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(INFOBOX, NULL);
    sfVector2f vector = option->visual->position;

    sfSprite_setTexture(sprite, texture, sfTrue);
    if (option->type == 1 || option->type == 4 || option->type == 6)
        vector.x = vector.x + 150;
    if (option->type == 4 || option->type == 3)
        vector.y = vector.y - 100;
    if (option->type == 2 || option->type == 3 || option->type == 7)
        vector.x = vector.x + 50;
    sfSprite_setPosition(sprite, vector);
    sfRenderWindow_drawSprite(w, sprite, NULL);
    vector.y = vector.y + 15;
    vector.x = vector.x + 15;
    print_info_text(w, option, vector, space);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void save_information(sfRenderWindow *w, button_t *op, space_t *space, int mod)
{
    static button_t *button = NULL;
    static space_t *safe = NULL;

    if (mod == 0) {
        button = op;
        safe = space;
    }
    if (mod == 1) {
        display_information(w, button, safe);
        button = NULL;
        safe = NULL;
    }
}