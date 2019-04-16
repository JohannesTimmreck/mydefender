/*
** EPITECH PROJECT, 2018
** my defender
** File description:
** create and destroy a tile
*/

#include "defender.h"

tiles_t *add_to_list(tiles_t *list, tiles_t *new)
{
    tiles_t *tmp = list;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return (list);
}

tiles_t *create_tile_list(char **map)
{
    tiles_t *begin = malloc(sizeof(tiles_t));
    tiles_t *new;
    sfVector2f pos;

    begin->next = NULL;
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            pos.x = x * TILE_SIZE;
            pos.y = y * TILE_SIZE;
            new = create_tile_list_entry(map[y][x], pos);
            begin = add_to_list(begin, new);
        }
    }
    new = begin->next;
    free(begin);
    return (new);
}

void destroy_tile_list(tiles_t *tile_list)
{
    tiles_t *tmp = tile_list->next;

    for (tiles_t *tile = tile_list; tile != NULL; tile = tmp) {
        sfSprite_destroy(tile->visual->sprite);
        sfTexture_destroy(tile->visual->texture);
        free(tile->visual);
        tmp = tile->next;
        free(tile);
    }
}