/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** create_buildspace_list
*/

#include "defender.h"

space_t *add_to_last_space(space_t *list, space_t *next)
{
    space_t *tmp = list;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = next;
    return (list);
}

space_t *create_space_list(int y, int x, space_t *space)
{
    space_t *next;
    sfVector2f position;

    x = x * TILE_SIZE;
    y = y * TILE_SIZE;
    position = create_vector(x, y);
    next = create_space(position);
    if (space == NULL)
        return (next);
    space = add_to_last_space(space, next);
    return (space);
}

space_t *check_for_buildspace(char **map, space_t *sp, int x, int y)
{
    if (map[y][x] == 'T')
        sp = create_space_list(y, x, sp);
    return (sp);
}

space_t *create_buildspace(char **map)
{
    int y = 0;
    int x = 0;
    space_t *space = NULL;

    while (map[y] != 0) {
        while (map[y][x] != '\0') {
            x++;
            space = check_for_buildspace(map, space, x, y);
        }
        x = 0;
        y++;
    }
    return (space);
}