/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "defender.h"

enemy_stats_t *create_enemy_stats(int level)
{
    enemy_stats_t *stats = malloc(sizeof(enemy_stats_t));
    float speed[3] = {SPEED_LV1, SPEED_LV2, SPEED_LV3};
    int health[3] = {HEALTH_LV1, HEALTH_LV2, HEALTH_LV3};
    int dmg[3] = {DMG_LV1, DMG_LV2, HEALTH_LV3};
    int reward[3] = {REWARD_LV1, REWARD_LV2, REWARD_LV3};

    stats->level = level;
    stats->dmg = dmg[level - 1];
    stats->max_health = health[level - 1];
    stats->health = stats->max_health;
    stats->speed = speed[level - 1];
    stats->reward = reward[level - 1];
    return (stats);
}

enemy_t *create_enemy(int level)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    enemy->vs = create_enemy_visual(level);
    enemy->hb = create_healthbar();
    enemy->stats = create_enemy_stats(level);
    enemy->status = WAITING;
    enemy->attacked = sfFalse;
    enemy->slowed = sfFalse;
    enemy->anim_sprite = 1;
    enemy->direction = 0;
    enemy->next = NULL;
    return (enemy);
}

enemy_t *link_enemies(enemy_t *list, enemy_t *new)
{
    enemy_t *tmp = list;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return (list);
}

enemy_t *create_enemy_list(char *wave_info)
{
    char **enemy_types = split_str(wave_info, '_');
    char **type_info;
    enemy_t *list = malloc(sizeof(enemy_t));
    enemy_t *new;

    list->next = NULL;
    for (int count = 0; enemy_types[count] != NULL; count++) {
        type_info = split_str(enemy_types[count], ':');
        for (int amount = my_getnbr(type_info[1]); amount > 0; amount--) {
            new = create_enemy(my_getnbr(type_info[0]));
            list = link_enemies(list, new);
        }
        free_arr(type_info);
    }
    new = list->next;
    free(list);
    return (new);
}