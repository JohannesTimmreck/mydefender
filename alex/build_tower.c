/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** build_tower
*/

#include "defender.h"

void change_space(char *filename, visual_t *visual)
{
    visual->animrect.top = 0;
    visual->texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setTextureRect(visual->sprite, visual->animrect);
}

tstats_t *update_towerstats(int type, int atk, int spd, int range)
{
    tstats_t *towerstats = malloc(sizeof(tstats_t));

    towerstats->atk = atk;
    if (type == 3)
        towerstats->magic = 1;
    towerstats->spd = spd / 4;
    towerstats->range = range * 10;
    if (type == 1 || type == 4)
        towerstats->refund = 40;
    if (type == 2)
        towerstats->refund = 80;
    if (type == 3)
        towerstats->refund = 60;
    return (towerstats);
}

void assign_sprite(space_t *space, int type)
{
    if (type == 1)
        change_space(PATH_TO_ARCHER, space->visual);
    if (type == 2)
        change_space(PATH_TO_ARTILLERY, space->visual);
    if (type == 3)
        change_space(PATH_TO_MAGE, space->visual);
    if (type == 4)
        change_space(PATH_TO_ICE, space->visual);
    if (type == 6)
        change_space(BUILDSPACE, space->visual);
    sfMusic_play(space->build);
}

void assign_sound(space_t *space, int type)
{
    switch (type) {
        case 1:
            space->shoot = create_sound(ARCH_SOUND, 20, sfFalse);
            break;
        case 2:
            space->shoot = create_sound(ARTY_SOUND, 20, sfFalse);
            break;
        case 4:
        case 3:
            space->shoot = create_sound(MAGE_SOUND, 20, sfFalse);
    }
}

tstats_t *assign_stats(int type)
{
    tstats_t *towerstats = malloc(sizeof(tstats_t));

    if (type == 1)
        towerstats = update_towerstats(1, 5, 5, 15);
    if (type == 2)
        towerstats = update_towerstats(2, 20, 12, 15);
    if (type == 3)
        towerstats = update_towerstats(3, 15, 7, 15);
    if (type == 4)
        towerstats = update_towerstats(4, 0, 0, 15);
    towerstats->cost = towerstats->refund * 2;
    towerstats->clock = sfClock_create();
    return (towerstats);
}