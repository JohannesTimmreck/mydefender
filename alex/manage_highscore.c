/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** manage_highscore
*/

#include "defender.h"

char *get_highscore(void)
{
    int fd = open("highscores.txt", O_RDONLY);
    char * line = malloc(sizeof(char) * 4);

    if (fd == -1)
        return ("000");
    read(fd, line, 3);
    line[3] = '\0';
    close (fd);
    return (line);
}

void check_for_new_highscore(int amount, int map)
{
    char *line = get_highscore();
    int fd;

    fd = open("highscores.txt", O_WRONLY);
    if (fd == -1)
        return;
    if ((line[map - 1] - '0') < amount) {
        line[map - 1] = amount + '0';
        write(fd, line, 3);
    }
    close(fd);
}
