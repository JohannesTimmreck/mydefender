/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** upgrade or sell
*/

#include "defender.h"

void upgrade_towerstats(space_t *space, int atk, int spd, int range)
{
    space->towerstats->atk = atk;
    space->towerstats->spd = spd / 4;
    space->towerstats->range = range * 10;
}

void upgrade_tier_one(space_t *space)
{
    int costs = space->towerstats->cost;
    int refund = space->towerstats->refund;

    space->level = space->level + 1;
    if (space->towertype == 1)
        upgrade_towerstats(space, 7, 4, 16);
    if (space->towertype == 2)
        upgrade_towerstats(space, 40, 11, 17);
    if (space->towertype == 3)
        upgrade_towerstats(space, 25, 6, 19);
    if (space->towertype == 4)
        upgrade_towerstats(space, 0, 0, 18);
    space->towerstats->cost = (costs + (costs / 2));
    space->towerstats->refund = (refund + (refund / 2));
}

void upgrade_tier_two(space_t *space)
{
    int costs = space->towerstats->cost;
    int refund = space->towerstats->refund;

    space->level = space->level + 1;
    if (space->towertype == 1)
        upgrade_towerstats(space, 10, 3, 18);
    if (space->towertype == 2)
        upgrade_towerstats(space, 55, 11, 19);
    if (space->towertype == 3)
        upgrade_towerstats(space, 35, 5, 23);
    if (space->towertype == 4)
        upgrade_towerstats(space, 0, 0, 20);
    space->towerstats->cost = (costs + (costs / 2));
    space->towerstats->refund = (refund + (refund / 2));
}

void sell_tower(space_t *space)
{
    sfClock_destroy(space->towerstats->clock);
    free (space->towerstats);
    sfMusic_destroy(space->shoot);
    if (space->projectile != NULL) {
        free_projectile_list(space->projectile);
        space->projectile = NULL;
    }
    space->attack = sfFalse;
    space->level = 0;
    space->towertype = 0;
    space->buildon = 0;
}
