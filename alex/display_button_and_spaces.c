/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** display
*/

#include "defender.h"

void display_costs(sfRenderWindow *window, button_t *options, space_t *space)
{
    sfFont *font = sfFont_createFromFile(FONT);
    sfText *costs = create_text(sfYellow, 8, options->visual->position, font);
    sfVector2f vector;

    vector.x = options->visual->position.x + 21;
    if (options->type == 1 || options->type == 4)
        vector.x = options->visual->position.x + 23;
    vector.y = options->visual->position.y + 51;
    sfText_setPosition(costs, vector);
    if (options->type == 1 || options->type == 4)
        sfText_setString(costs, "80");
    if (options->type == 2)
        sfText_setString(costs, "160");
    if (options->type == 3)
        sfText_setString(costs, "120");
    if (options->type == 7)
        sfText_setString(costs, my_int_to_str((space->towerstats->cost *1.5)));
    sfRenderWindow_drawText(window, costs, NULL);
    sfFont_destroy(font);
    sfText_destroy(costs);
}

int display_buildoptions(sfRenderWindow *w, button_t *options, space_t *space)
{
    button_t *tmp = options;
    int hover = 0;

    while (tmp != NULL) {
        sfRenderWindow_drawSprite(w, tmp->visual->sprite, NULL);
        display_costs(w, tmp, space);
        if (tmp->hover == sfTrue && tmp->type != 5) {
            hover = 1;
            save_information(w, tmp, space, 0);
        }
        tmp = tmp->next;
    }
    return (hover);
}

void draw_projectile(sfRenderWindow *window, projectile_t *projectile)
{
    for (projectile_t *tmp = projectile; tmp != NULL; tmp = tmp->next)
        sfRenderWindow_drawSprite(window, tmp->visual->sprite, NULL);
}

int display_sprites(sfRenderWindow *window, space_t *tmp)
{
    int x = 0;

    if (tmp->options_active == sfFalse) {
        sfRenderWindow_drawSprite(window, tmp->visual->sprite, NULL);
        draw_projectile(window, tmp->projectile);
        return (x);
    }
    if (tmp->options_active == sfTrue && tmp->buildon == 0) {
        sfRenderWindow_drawSprite(window, tmp->buildwheel->sprite, NULL);
        x = display_buildoptions(window, tmp->buildoptions, tmp);
        return (x);
    }
    if (tmp->options_active == sfTrue && tmp->buildon == 1) {
        sfRenderWindow_drawSprite(window, tmp->visual->sprite, NULL);
        draw_projectile(window, tmp->projectile);
        sfRenderWindow_drawSprite(window, tmp->upgradewheel->sprite, NULL);
        x = display_buildoptions(window, tmp->upgradeoptions, tmp);
        return (x);
    }
    return (x);
}

void display_buildspaces(sfRenderWindow *window, space_t *space)
{
    space_t *tmp = space;
    int x = 0;
    int y = 0;

    while (tmp != NULL) {
        x = display_sprites(window, tmp);
        if (x == 1)
            y = 1;
        tmp = tmp->next;
    }
    if (y == 1)
        save_information(window, space->buildoptions, space, 1);
}