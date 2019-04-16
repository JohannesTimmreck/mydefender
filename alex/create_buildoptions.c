/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** johannes utils
*/

#include "defender.h"

sfVector2f create_vector(int x, int y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfVector2f change_position(sfVector2f vector, int type)
{
    if (type == 2 || type == 7)
        vector.x = vector.x + 177;
    if (type == 3)
        vector.y = vector.y + 177;
    if (type == 4)
        vector.x = vector.x - 177;
    if (type == 5) {
        vector.x = vector.x + 88;
        vector.y = vector.y - 89;
    }
    if (type == 6) {
        vector.x = vector.x - 88;
        vector.y = vector.y - 201;
    }
    return (vector);
}

button_t *create_buildoptions(sfVector2f vector)
{
    button_t *options;
    button_t *next;
    sfVector2f position;
    int type = 2;

    position.x = vector.x - 68;
    position.y = vector.y - 68;
    options = create_button(1, position);
    while (type != 6) {
        position = change_position(position, type);
        next = create_button(type, position);
        options = add_to_last_button(options, next);
        type++;
    }
    return (options);
}

button_t *create_upgradeoptions(sfVector2f vector)
{
    button_t *options;
    button_t *next;
    sfVector2f position;
    int type = 6;

    position.x = vector.x + 20;
    position.y = vector.y + 133;
    options = create_button(5, position);
    while (type != 8) {
        position = change_position(position, type);
        next = create_button(type, position);
        options = add_to_last_button(options, next);
        type++;
    }
    return (options);
}