/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** end
*/

#include "defender.h"

int check_for_ending(map_t *map, enemy_info_t *enemy)
{
    int res = 0;

    if (map->castle->health <= 0)
        return (-1);
    if (check_wave_alive(enemy->enemy_waves) == sfFalse) {
        res = map->castle->health / 66;
        res = res + 1;
        return (res);
    }
    return (0);
}

int end_the_game(sfRenderWindow *w, map_t *m, enemy_info_t *e, int map)
{
    int res = check_for_ending(m, e);

    if (res != 0) {
        res = res - 1;
        res = game_ends(w, res, map);
    }
    return (res);
}