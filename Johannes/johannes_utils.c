/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** johannes utils
*/

#include "defender.h"

void free_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

sfBool check_for_number(char *str)
{
    for (int i = 0; str[i + 1] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return (sfFalse);
        }
    }
    return (sfTrue);
}

sfVector2f create_vectorf(float x, float y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}