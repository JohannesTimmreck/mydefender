/*
** EPITECH PROJECT, 2018
** defender
** File description:
** music
*/

#include "defender.h"

sfMusic *create_sound(char *path, int volume, sfBool loop)
{
    sfMusic *sound = sfMusic_createFromFile(path);

    sfMusic_setVolume(sound, volume);
    sfMusic_setLoop(sound, loop);
    return (sound);
}