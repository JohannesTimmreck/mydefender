/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** check_enemies_alive
*/

#include "defender.h"

sfBool check_enemies_alive(enemy_t *enemy_list)
{
    for (enemy_t *enemy = enemy_list; enemy != NULL; enemy = enemy->next) {
        if (enemy->status != DEAD)
            return (sfTrue);
    }
    return (sfFalse);
}

sfBool check_wave_alive(enemy_wave_t *waves)
{
    for (enemy_wave_t *wave = waves; wave != NULL; wave = wave->next) {
        if (wave->spawned == sfFalse)
            return (sfTrue);
        if (check_enemies_alive(wave->enemy_list) == sfTrue)
            return (sfTrue);
    }
    return (sfFalse);
}