/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** create_tiles
*/

#include "defender.h"


visual_t *create_tile_visual(char *path_to_texture, sfVector2f pos,
    sfVector2f size)
{
    visual_t *visual = malloc(sizeof(visual_t));

    visual->texture = sfTexture_createFromFile(path_to_texture, NULL);
    visual->sprite = sfSprite_create();
    visual->position.x = pos.x;
    visual->position.y = pos.y;
    visual->hitbox = create_intrect(pos, size);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, visual->position);
    return (visual);
}

void set_tile(tiles_t *tile, char type, char *texture_path, sfVector2f pos)
{
    sfVector2f size = {TILE_SIZE, TILE_SIZE};

    if (type == 'R' || type == 'U' || type == 'L' || type == 'D')
        tile->type = 'P';
    tile->visual = create_tile_visual(texture_path, pos, size);
}

tiles_t *create_tile_list_entry(int type, sfVector2f pos)
{
    tiles_t *tile = malloc(sizeof(tiles_t));
    char *texture_path[8] = {PATH_TO_BUILD, PATH_TO_START_DOWN, PATH_TO_PATH,
        PATH_CORN_DOWN_RIGHT, PATH_CORN_RIGHT_UP, PATH_CORN_UP_LEFT,
        PATH_CORN_LEFT_DOWN, PATH_TO_GRASS};
    char *path_num_str = "TSPRULD";

    tile->type = type;
    for (int i = 0; i < 8; i++) {
        if (path_num_str[i] == type) {
            set_tile(tile, type, texture_path[i], pos);
            break;
        }
        if (i == 7)
            set_tile(tile, type, texture_path[7], pos);
    }
    tile->next = NULL;
    return (tile);
}