/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "defender.h"

void set_start_tile(visual_t *s, int direction)
{
    switch (direction) {
        case UP:
            s->texture = sfTexture_createFromFile(PATH_TO_START_UP, NULL);
            sfSprite_setTexture(s->sprite, s->texture, sfTrue);
            break;
        case LEFT:
            s->texture = sfTexture_createFromFile(PATH_TO_START_LEFT, NULL);
            sfSprite_setTexture(s->sprite, s->texture, sfTrue);
            break;
        case DOWN:
            s->texture = sfTexture_createFromFile(PATH_TO_START_DOWN, NULL);
            sfSprite_setTexture(s->sprite, s->texture, sfTrue);
            break;
        case RIGHT:
            s->texture = sfTexture_createFromFile(PATH_TO_START_RIGHT, NULL);
            sfSprite_setTexture(s->sprite, s->texture, sfTrue);
    }
}

void find_start_tile(tiles_t *tiles, int direction)
{
    for (tiles_t *tile = tiles; tile != NULL; tile = tile->next) {
        if (tile->type == 'S') {
            set_start_tile(tile->visual, direction);
        }
    }
}