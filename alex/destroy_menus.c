/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** destroy_menus
*/

#include "defender.h"

void destroy_menu(menu_t *menu, int pause)
{
    destroy_visual(menu->background);
    sfText_destroy(menu->text);
    menu->options = destroy_buttons(menu->options);
    if (pause == 1)
        sfRectangleShape_destroy(menu->rect);
    sfMusic_destroy(menu->move);
    sfMusic_destroy(menu->select);
    free (menu);
}

void destroy_select(select_t *select)
{
    destroy_visual(select->one);
    destroy_visual(select->two);
    destroy_visual(select->three);
    destroy_visual(select->background);
    destroy_visual(select->star);
    select->level = destroy_buttons(select->level);
    sfText_destroy(select->name);
    sfMusic_destroy(select->move);
    sfMusic_destroy(select->select);
    free (select);
}

void destroy_end(end_t *end)
{
    destroy_visual(end->background);
    destroy_visual(end->stars);
    sfText_destroy(end->text);
    sfText_destroy(end->button_text);
    end->back = destroy_buttons(end->back);
    sfMusic_destroy(end->move);
    sfMusic_destroy(end->select);
    free (end);
}

void destroy_how_to(sfFont *f, sfText *t, sfSprite *s)
{
    sfText_destroy(t);
    sfFont_destroy(f);
    sfSprite_destroy(s);
}