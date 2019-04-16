/*
** EPITECH PROJECT, 2018
** defender
** File description:
** castle.c
*/

#include "defender.h"

visual_t *set_healthbar_visual(char *path, sfVector2f pos, sfVector2f size)
{
    visual_t *healthbar = malloc(sizeof(visual_t));

    healthbar->texture = sfTexture_createFromFile(path, NULL);
    healthbar->position = pos;
    healthbar->animrect = create_intrect(create_vectorf(0, 0), size);
    healthbar->sprite = sfSprite_create();
    sfSprite_setTexture(healthbar->sprite, healthbar->texture, sfTrue);
    sfSprite_setPosition(healthbar->sprite, healthbar->position);
    return (healthbar);
}

void draw_castle(sfRenderWindow *window, castle_t *c)
{
    sfRenderWindow_drawSprite(window, c->visual->sprite, NULL);
    sfRenderWindow_drawSprite(window, c->healthbar->empty->sprite, NULL);
    sfRenderWindow_drawSprite(window, c->healthbar->curr->sprite, NULL);
}

healthbar_t *create_castle_healthbar(sfVector2f pos)
{
    healthbar_t *healthbar = malloc(sizeof(healthbar_t));

    healthbar->curr = set_healthbar_visual(FULL_CASTLE_HB,
        create_vectorf(pos.x + 4, pos.y - 31), create_vectorf( 392, 22));
    healthbar->empty = set_healthbar_visual(EMPTY_CASTLE_HB,
        create_vectorf(pos.x, pos.y - 35), create_vectorf( 400, 30));
    return (healthbar);
}

visual_t *create_castle_visual(sfVector2f pos)
{
    visual_t *castle = malloc(sizeof(visual_t));

    castle->position = pos;
    castle->hitbox = create_intrect(pos, create_vectorf(342, 400));
    castle->texture = sfTexture_createFromFile(CASTLE_PATH, NULL);
    castle->sprite = sfSprite_create();
    sfSprite_setTexture(castle->sprite, castle->texture, sfTrue);
    sfSprite_setPosition(castle->sprite, castle->position);
    return (castle);
}

castle_t *create_castle(tiles_t *tile_list)
{
    sfVector2f pos = get_castle_pos(tile_list);
    castle_t *castle = malloc(sizeof(castle_t));

    pos.y -= 242;
    pos.x -= 10;
    castle->max_health = CASTLE_HEALTH;
    castle->health = castle->max_health;
    castle->healthbar = create_castle_healthbar(pos);
    castle->visual = create_castle_visual(pos);
    return (castle);
}
