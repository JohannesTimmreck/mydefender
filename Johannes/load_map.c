/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** map_load
*/

#include "defender.h"

sfVector2f get_castle_pos(tiles_t *tile_list)
{
    sfVector2f error = {0, 0};
    for (tiles_t *tile = tile_list; tile != NULL; tile = tile->next) {
        if (tile->type == 'G') {
            return (tile->visual->position);
        }
    }
    return (error);
}

char **create_map(FILE *map_stream)
{
    size_t len = 1;
    char **map = malloc(sizeof(char *) * (12));

    map[11] = NULL;
    for (size_t i = 0; i < 11; i++) {
        map[i] = NULL;
        getline(&map[i], &len, map_stream);
    }
    fclose(map_stream);
    return (map);
}

map_t *load_map(char *file_path){
    FILE *map_stream = fopen(file_path, "r+");
    map_t *map = malloc(sizeof(map_t));

    map->map = create_map(map_stream);
    map->map_correct = sfTrue;
    map->tile_list = create_tile_list(map->map);
    get_map_start(map);
    map->castle = create_castle(map->tile_list);
    return (map);
}

void draw_map(map_t *map, sfRenderWindow *window)
{
    for (tiles_t *tmp = map->tile_list; tmp != NULL; tmp = tmp->next)
        sfRenderWindow_drawSprite(window, tmp->visual->sprite, NULL);
    draw_castle(window, map->castle);
}

void destroy_map(map_t *map)
{
    destroy_tile_list(map->tile_list);
    for (int y = 0; map->map[y] != NULL; y++)
        free(map->map[y]);
    free(map->map);
    free(map);
}