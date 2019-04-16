/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** end_menu
*/

#include "defender.h"

sfVector2f change_vector(int amount)
{
    sfVector2f vector = create_vector(660, 600);

    if (amount == 1)
        vector.x = vector.x + 360;
    if (amount == 2) {
        vector.x = vector.x + 180;
        vector.y = vector.y - 100;
    }
    return (vector);
}

void display_stars(sfRenderWindow *window, end_t *end, sfClock *c, int res)
{
    sfVector2f vector = end->stars->position;
    static int amount = 0;
    int loop = 0;
    sfTime time = sfClock_getElapsedTime(c);
    float sec = time.microseconds /1000000.0;

    if (res == 1) {
        amount = 0;
        return;
    }
    if (sec >= 0.5 && amount != end->amount_stars) {
        amount++;
        sfClock_restart(c);
    }
    while (loop != amount) {
        sfRenderWindow_drawSprite(window, end->stars->sprite, NULL);
        loop++;
        vector = change_vector(loop);
        sfSprite_setPosition(end->stars->sprite, vector);
    }
}

void display_gameend(sfRenderWindow *window, end_t *end, sfClock *clock)
{
    if (end->result == 0) {
        sfText_setString(end->text, "GAME OVER");
    } else {
        sfText_setString(end->text, "VICTORY");
    }
    sfRenderWindow_drawSprite(window, end->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, end->back->visual->sprite, NULL);
    sfRenderWindow_drawText(window, end->text, NULL);
    sfText_setString(end->button_text, "BACK TO MENU");
    sfRenderWindow_drawText(window, end->button_text, NULL);
    sfSprite_setPosition(end->stars->sprite, end->stars->position);
    display_stars(window, end, clock, 0);
    sfRenderWindow_display(window);
}

int game_ends(sfRenderWindow *window, int game_state, int map)
{
    sfFont *font = sfFont_createFromFile(FONT);
    end_t *end = create_end(font, game_state);
    sfEvent *event = malloc(sizeof(sfEvent));
    sfClock *clock = sfClock_create();
    int leave = 0;

    check_for_new_highscore(end->amount_stars, map);
    while (leave == 0) {
        display_gameend(window, end, clock);
        while (sfRenderWindow_pollEvent(window, event) == sfTrue)
            leave = manage_end_input(window, event, end);
    }
    display_stars(window, end, clock, 1);
    sfClock_destroy(clock);
    destroy_end(end);
    sfFont_destroy(font);
    return (leave);
}