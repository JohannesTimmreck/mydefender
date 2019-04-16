/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** select_screen
*/

#include "defender.h"

void change_text(sfText *text)
{
    static int cnt = 0;
    sfVector2f vector = create_vector(250, 100);

    cnt++;
    if (cnt == 4) {
        sfText_setString(text, "BACK TO MENU");
        vector = create_vector(790, 840);
        sfText_setPosition(text, vector);
        cnt = 0;
        return;
    }
    if (cnt == 1)
        sfText_setString(text, "LEVEL 1");
    if (cnt == 2)
        sfText_setString(text, "LEVEL 2");
    if (cnt == 3)
        sfText_setString(text, "LEVEL 3");
    vector.x = (vector.x + (605 * (cnt - 1)));
    sfText_setPosition(text, vector);
}

void display_highscores(int nb, sfRenderWindow *window, select_t *star)
{
    sfVector2f vector = star->star->position;
    int cnt = 0;

    if (nb < 0 || nb > 3)
        return;

    sfSprite_setPosition(star->star->sprite, vector);
    while (cnt != nb) {
        sfRenderWindow_drawSprite(window, star->star->sprite, NULL);
        vector.x = vector.x + 150;
        sfSprite_setPosition(star->star->sprite, vector);
        cnt++;
    }
}

void display_map_stars(sfRenderWindow *window, select_t *select, char *line)
{
    int cnt = 0;
    sfVector2f vector = select->star->position;

    while (line[cnt] != '\0') {
        display_highscores((line[cnt] - '0'), window, select);
        select->star->position.x = select->star->position.x + 605;
        cnt++;
    }
    select->star->position.x = vector.x;
}

void display_selection(sfRenderWindow *window, select_t *select)
{
    button_t *tmp = select->level;

    sfRenderWindow_drawSprite(window, select->background->sprite, NULL);
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(window, tmp->visual->sprite, NULL);
        tmp = tmp->next;
    }
    for (int x = 0; x != 4; x++) {
        change_text(select->name);
        sfRenderWindow_drawText(window, select->name, NULL);
    }
    sfRenderWindow_drawSprite(window, select->one->sprite, NULL);
    sfRenderWindow_drawSprite(window, select->two->sprite, NULL);
    sfRenderWindow_drawSprite(window, select->three->sprite, NULL);
}

int select_map_to_play(sfRenderWindow *window)
{
    sfEvent *event = malloc(sizeof(sfEvent));
    sfFont *font = sfFont_createFromFile(FONT);
    select_t *select = create_selection(font);
    int selection = 0;
    char *highscore = get_highscore();

    while (selection == 0) {
        display_selection(window, select);
        display_map_stars(window, select, highscore);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, event) == sfTrue)
            selection = manage_selection(window, event, select);
    }
    free (highscore);
    destroy_select(select);
    sfFont_destroy(font);
    return (selection);
}