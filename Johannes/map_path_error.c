/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "defender.h"

void path_error(map_t *map, int sign)
{
    if (sign == 1)
        write(2, "PATH NOT CONNECTED WITH STARTPOINT\n", 35);
    else
        write(2, "STARTPOINT IS NOT AT BORDER OF MAP\n", 35);
    map->map_correct = sfFalse;
    map->start_direction = -1;
}
