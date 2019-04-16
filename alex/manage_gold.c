/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** johannes utils
*/

#include "defender.h"

int check_for_valid_click(int gp, space_t *space, button_t *clicked)
{
    if ((clicked->type == 1 || clicked->type == 4) && gp < 80)
        return (0);
    if (clicked->type == 2 && gp < 160)
        return (0);
    if (clicked->type == 3 && gp < 120)
        return (0);
    if (clicked->type == 7 && (space->towerstats->cost * 1.5) > gp)
        return (0);
    if (clicked->type == 7 && space->level == 3)
        return (0);
    return (1);
}

int upddate_player_money(int gp, space_t *space, button_t *clicked)
{
    if (check_for_valid_click(gp, space, clicked) == 0)
        return (gp);
    if (clicked->type == 6) {
        gp = gp + space->towerstats->refund;
        clicked->next->type = 7;
        clicked->next->visual->animrect.left = 360;
    }
    release_button_effect(space, clicked);
    if (clicked->type < 5 || clicked->type == 7)
        gp = gp - space->towerstats->cost;
    if (clicked->type == 7 && space->level == 3) {
        clicked->type = 5;
        clicked->visual->animrect.left = 240;
    }
    return (gp);
}