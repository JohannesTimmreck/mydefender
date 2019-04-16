/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** johannes utils
*/

#include "defender.h"

int mainloop(sfRenderWindow *window, map_t *map, enemy_info_t *e, int select)
{
    gp_t *g = create_gameloop(map, e);
    int end = 0;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, g->event) == sfTrue)
            g->value = event_management(window, g->event, g->space, g->value);
        end = check_for_player_exit(window, g);
        if (end != 0)
            return (end);
        manage_mainloop(window, e, map, g);
        sfRenderWindow_drawText(window, g->amount, NULL);
        sfRenderWindow_display(window);
        if (end_the_game(window, map, e, select) == 1) {
            destroy_mainloop(g);
            return (2);
        }
    }
    destroy_mainloop(g);
    return (0);
}

enemy_info_t *assign_enemys(int selected)
{
    enemy_info_t *enemy_info;

    if (selected == 1)
        enemy_info = init_enemy_info("test_wave");
    if (selected == 2)
        enemy_info = init_enemy_info("wave2");
    if (selected == 3)
        enemy_info = init_enemy_info("wave3");
    return (enemy_info);
}

map_t *assign_map(int selected)
{
    map_t *map;

    if (selected == 1)
        map = load_map("example_map");
    if (selected == 2)
        map = load_map("example_map2");
    if (selected == 3)
        map = load_map("example_map3");
    if (map->map_correct == sfFalse) {
        destroy_map(map);
        return (NULL);
    }
    return (map);
}

int load_selected_map(sfRenderWindow *window, int selected)
{
    map_t *map = assign_map(selected);
    enemy_info_t *enemy_info = assign_enemys(selected);
    int res = 0;

    if (map == NULL)
        return (1);
    res = mainloop(window, map, enemy_info, selected);
    destroy_map(map);
    destroy_enemy_info(enemy_info);
    return (res);
}

int main(void)
{
    sfRenderWindow *window = create_window(1920, 1080);
    int res = 2;
    sfMusic *music = sfMusic_createFromFile(WAITING_SOUND);

    sfRenderWindow_setFramerateLimit(window, 120);
    sfMusic_setVolume(music, 20);
    sfMusic_setLoop(music, sfTrue);
    while (res == 2) {
        sfMusic_play(music);
        res = create_main_menu(window);
        sfRenderWindow_clear(window, sfRed);
        if (res > 0) {
            sfMusic_stop(music);
            res = load_selected_map(window, res);
        }
    }
    sfMusic_destroy(music);
    sfRenderWindow_destroy(window);
    return (0);
}