/*
** EPITECH PROJECT, 2019
** combine_strings
** File description:
** combine two strings
*/

#include "defender.h"

int get_string_len(char *str)
{
    int counter = 0;

    while (str[counter] != '\0')
        counter++;
    return (counter);
}

char *combine_strings(char *one, char *two)
{
    int y = get_string_len(one);
    int len = y + get_string_len(two);
    char *res = malloc(sizeof(char) * (len + 1));

    res[len] = '\0';
    for (int x = 0; one[x] != '\0'; x++)
        res[x] = one[x];
    for (int x = 0; two[x] != '\0'; x++)
        res[y + x] = two[x];
    return (res);
}
