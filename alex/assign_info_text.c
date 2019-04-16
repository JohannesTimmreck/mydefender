/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** assign_info_text
*/

#include "defender.h"

char *assign_title(int type, space_t *space)
{
    if (type == 1)
        return ("ARCHER TOWER");
    if (type == 2)
        return ("BOMBARD TOWER");
    if (type == 3)
        return ("MAGICAL CONSTRUCT");
    if (type == 4)
        return ("WINTER SHARD");
    if (type == 6)
        return ("SELL TOWER");
    if (type == 7 && space->level == 1)
        return ("TIER II UPGRADE");
    if (type == 7 && space->level == 2)
        return ("TIER III UPGRADE");
    return ("ERROR");
}

char *assign_text_build(int type)
{
    char *one = "ERR";
    char *two = "OR";

    if (type == 1) {
        one = "\n\nA SHELTER FOR \nELVEN ARCHERS THAT";
        two = "\nSTRIKE ENEMIES FROM AFAR\n\nATK:5\nRELOAD:FAST\n";
    }
    if (type == 2) {
        one = "\n\nBOMBARDS FIRE BOMBS\nAT THE ENEMY, DEALING\nAREA DAMAGE";
        two = " AROUND\nTHE INITAL TARGET\n\nATK:20\nRELOAD:VERY SLOW\n";
    }
    if (type == 3) {
        one = "\n\nTHIS CONSTRUCT FIRES \nMAGICAL ORBS THAT HAVE\nAN";
        two = "INSANE REACH\n\nATK:15\nRELOAD:SLOW\n";
    }
    if (type == 4) {
        one = "\n\nWE FOUND THIS SHARD\nON A MARKET ONCE\nBY HARNISSING\nITS";
        two = " ENERGY, WE COULD\nSLOW DOWN ENEMIES\n\n";
    }
    return (combine_strings(one, two));
}

char *get_upgrade_1_type(int type)
{
    char *one = "ERR";
    char *two = "OR";

    if (type == 1) {
        one = "\n\nBETTER ARROWS\nBETTER DAMAGE\n";
        two = "\nATK:7\nRELOAD:FAST\n";
    }
    if (type == 2) {
        one = "\n\nWITH THESE NEW BOMBS\nWE SURELY WILL DEAL\n MASSIVE DAMAGE";
        two = "\n\nATK:40\nRELOAD:VERY SLOW\n";
    }
    if (type == 3) {
        one = "\n\nTHE DECISION TO LET A\nNOVICE BUILD A HIGHLY\nADVANCED MA";
        two = "GICAL WEAPON\nSURELY WAS A BAD ONE\n\nATK:25\nRELOAD:MEDIUM\n";
    }
    if (type == 4) {
        one = "\n\nWE FOUND SOME MORE SHARDS\nAND MANAGED TO FUSE THEM\n";
        two = "TOGETHER INCREASING\nTHE RANGE OF THE EFFECT\n\n";
    }
    return (combine_strings(one, two));
}

char *get_upgrade_2_type(int type)
{
    char *one = "ERR";
    char *two = "OR";

    if (type == 1) {
        one = "\n\nEVEN BETTER ARROWS\nEVEN BETTER DAMAGE\n";
        two = "\nATK:10\nRELOAD: VERY FAST\n";
    }
    if (type == 2) {
        one = "\n\nTHERE IS AN OLD DWARVEN\n SAYING:\nTHERE";
        two = "CAN NEVER BE\nTO MUCH GUNPOWDER\n\nATK:55\nRELOAD:SLOW\n";
    }
    if (type == 3) {
        one = "\n\nOK\n THIS TIME WE HIRED\n PROFESSIONALS TO FIX";
        two = " IT\n\nATK:35\nRELOAD:FAST\n";
    }
    if (type == 4) {
        one = "\n\nMORE SHARDS\nMORE RANGE\nI CAN'T ";
        two = "FEEL MY FINGERS\nANYMORE\n\n";
    }
    return (combine_strings(one, two));
}