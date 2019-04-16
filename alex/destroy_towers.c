/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** destroy_towers
*/

#include "defender.h"

void destroy_visual(visual_t *visual)
{
    sfSprite_destroy(visual->sprite);
    sfTexture_destroy(visual->texture);
    free (visual);
}

void destroy_space_visual(space_t *space)
{
    destroy_visual(space->buildwheel);
    destroy_visual(space->upgradewheel);
    destroy_visual(space->visual);
}

button_t *destroy_buttons(button_t *button)
{
    if (button->next != NULL)
        button->next = destroy_buttons(button->next);
    if (button->next == NULL) {
        destroy_visual(button->visual);
        free (button);
    }
    return (NULL);
}

space_t *go_to_last_space(space_t *space)
{
    if (space->next != NULL)
        space->next = go_to_last_space(space->next);
    if (space->next == NULL) {
        destroy_space_visual(space);
        sfMusic_destroy(space->build);
        if (space->buildon == 1) {
            sfClock_destroy(space->towerstats->clock);
            sfMusic_destroy(space->shoot);
            free_projectile_list(space->projectile);
            free (space->towerstats);
        }
        space->buildoptions = destroy_buttons(space->buildoptions);
        free (space);
    }
    return (NULL);
}

void destroy_buildspace(space_t *space)
{
    space = go_to_last_space(space);
}