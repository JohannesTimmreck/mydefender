/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** create_buildspace
*/

#include "defender.h"

visual_t *create_wheel_visual(sfVector2f position, int type)
{
    visual_t *visual = malloc(sizeof(visual_t));
    sfVector2f size = create_vector(100, 100);

    visual->sprite = sfSprite_create();
    position.x = position.x - 100;
    position.y = position.y - 100;
    visual->position = position;
    if (type == 1)
        visual->texture = sfTexture_createFromFile(BUILDWHEEL, NULL);
    if (type == 2)
        visual->texture = sfTexture_createFromFile(UPGRADEWHEEL, NULL);
    visual->animrect = create_rect(0, 0 , 300, 300);
    size.x = 300;
    size.y = 300;
    visual->hitbox = create_intrect(position, size);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setTextureRect(visual->sprite, visual->animrect);
    sfSprite_setPosition(visual->sprite, visual->position);
    return (visual);
}

visual_t *create_visual_space(sfVector2f position)
{
    visual_t *visual = malloc(sizeof(visual_t));
    sfVector2f size = create_vector(100, 100);

    visual->sprite = sfSprite_create();
    visual->position = position;
    visual->texture = sfTexture_createFromFile(BUILDSPACE, NULL);
    visual->animrect = create_rect(0, 0 , 100, 100);
    visual->hitbox = create_intrect(position, size);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setTextureRect(visual->sprite, visual->animrect);
    sfSprite_setPosition(visual->sprite, visual->position);
    return (visual);
}

tstats_t *create_towerstats(void)
{
    tstats_t *tower = malloc(sizeof(tstats_t));

    tower->cost = 0;
    tower->refund = 0;
    tower->atk = 0;
    tower->magic = 0;
    tower->range = 0;
    tower->spd = 0;
    return (tower);
}

space_t *create_space(sfVector2f position)
{
    space_t *space = malloc(sizeof(space_t));

    space->buildon = 0;
    space->attack = sfFalse;
    space->atk_ready = sfFalse;
    space->options_active = sfFalse;
    space->towertype = 0;
    space->visual = create_visual_space(position);
    space->buildwheel = create_wheel_visual(position, 1);
    space->upgradewheel = create_wheel_visual(position, 2);
    space->buildoptions = create_buildoptions(position);
    space->upgradeoptions = create_upgradeoptions(position);
    space->build = create_sound(BUILD_SOUND, 15, sfFalse);
    space->level = 0;
    space->towerstats = create_towerstats();
    space->projectile = NULL;
    space->next = NULL;
    return (space);
}