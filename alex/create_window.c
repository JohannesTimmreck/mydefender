/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** johannes utils
*/

#include "defender.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    char *name = "WINDOW";

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, name, sfFullscreen, NULL);
    return (window);
}