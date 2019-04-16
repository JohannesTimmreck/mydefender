/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** load_waves
*/

#include "defender.h"

char *get_wave_information(FILE *enemy_stream)
{
    char *wave = NULL;
    size_t tmp = 1;

    getline(&wave, &tmp, enemy_stream);
    return (wave);
}

int get_num_of_waves(FILE *enemy_stream)
{
    size_t tmp = 1;
    char *num_of_waves = NULL;
    int return_value;

    getline(&num_of_waves, &tmp, enemy_stream);
    return_value = my_getnbr(num_of_waves);
    free(num_of_waves);
    return (return_value);
}

enemy_wave_t *create_new_wave(int current_wave, FILE *enemy_stream)
{
    char *wave_info = get_wave_information(enemy_stream);
    enemy_wave_t *wave = malloc(sizeof(enemy_wave_t));

    wave->spawned = sfFalse;
    wave->wave_num = current_wave;
    wave->next = NULL;
    wave->enemy_list = create_enemy_list(wave_info);
    return (wave);
}

enemy_wave_t *link_waves(enemy_wave_t *list, enemy_wave_t *new)
{
    enemy_wave_t *tmp = list;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return (list);
}

enemy_wave_t *load_enemy_waves(char *file_path)
{
    FILE *enemy_stream = fopen(file_path, "r+");
    int num_of_waves = get_num_of_waves(enemy_stream);
    enemy_wave_t *list = malloc(sizeof(enemy_wave_t));
    enemy_wave_t *new;

    list->next = NULL;
    for (int current_wave = 1; current_wave <= num_of_waves; current_wave++) {
        new = create_new_wave(current_wave, enemy_stream);
        list = link_waves(list, new);
    }
    fclose(enemy_stream);
    new = list->next;
    free(list);
    return (new);
}