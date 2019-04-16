/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** display_how_to
*/

#include "defender.h"

void display_build_help(sfRenderWindow *w, sfText *text, sfVector2f position)
{
    char *one;
    char *two;

    sfText_setCharacterSize(text, 10);
    sfText_setPosition(text, position);
    one = "NOW YOU MAY SELECT ONE OF THE TOWERS BY CLICKING ON IT\n";
    two = "IF YOU ARE NOT SURE WHAT THE TOWER DOES, YOU CAN READ THE INFO ";
    one = combine_strings(one, two);
    two = "ABOUT IT\nSIMPLY HOVER OVER THE TOWER ICON AND IT WILL APPEAR ";
    one = combine_strings(one, two);
    two = "TELLING YOU\nIN DEPTH INFORMATION ABOUT YOUR TOWER\n";
    one = combine_strings(one, two);
    sfText_setString(text, one);
    sfRenderWindow_drawText(w, text, NULL);
    free (one);
}

void display_upgrade_help(sfRenderWindow *w, sfText *text, sfVector2f position)
{
    char *one;
    char *two;

    sfText_setCharacterSize(text, 10);
    sfText_setPosition(text, position);
    one = "YOU NOW BUILD A TOWER, I AM PROUD OF YOU\nYOU MAY UPGRADE IT";
    two = " BY OPENING THE BUILD MENU AGAIN AND SELECTING UPGRADE,\nIN THE";
    one = combine_strings(one, two);
    two = " UPPER RIGHT CORNER\nAGAIN A INFOBOX FOR MORE INFORMATION WILL";
    one = combine_strings(one, two);
    two = " APPEAR IF YOU\nYOU HOVER OVER THE BUTTON\n\nTOWERS ALSO CAN";
    one = combine_strings(one, two);
    two = " BE SOLD IF YOU NO LONGER NEED THEM,\nSIMPLY SELECT THE";
    one = combine_strings(one, two);
    two = " SELL OPTION IN THE UPPER LEFT CORNER OF THE BUILD MENU\n";
    one = combine_strings(one, two);
    sfText_setString(text, one);
    sfRenderWindow_drawText(w, text, NULL);
    free (one);
}

void display_pause_help(sfRenderWindow *w, sfText *text, sfVector2f position)
{
    char *one;
    char *two;

    sfText_setCharacterSize(text, 10);
    sfText_setPosition(text, position);
    one = "BY PRESSING THE ESCAPE KEY, YOU CAN OPEN THE PAUSE MENU\n";
    two = "FROM THERE YOU CAN EXIT THE GAME, CLOSE IT OR CONTINUE\n";
    one = combine_strings(one, two);
    sfText_setString(text, one);
    sfRenderWindow_drawText(w, text, NULL);
    free (one);
}

void display_menu_help(sfRenderWindow *w, sfText *text, sfVector2f position)
{
    char *one;
    char *two;

    sfText_setCharacterSize(text, 10);
    sfText_setPosition(text, position);
    one = "SELECT ANY OF THE GIVEN BUILDSPACES, WHICH ARE INDICATED BY ";
    two = "THE\nHAMMERSYMBOL, AND CLICK ON THEM TO OPEN THE BUILD MENU.\n";
    one = combine_strings(one, two);
    sfText_setString(text, one);
    sfRenderWindow_drawText(w, text, NULL);
    free (one);
}

void display_help(sfRenderWindow *window, sfText *text, sfVector2f position)
{
    char *one = "PRESS ANY KEY TO EXIT THE MANUEL\n";
    sfVector2f vector = create_vector(30, 1000);

    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, vector);
    sfText_setString(text, one);
    sfRenderWindow_drawText(window, text, NULL);
    display_menu_help(window, text, position);
    position.y = position.y + 235;
    display_build_help(window, text, position);
    position.y = position.y + 235;
    display_upgrade_help(window, text, position);
    position.y = position.y + 235;
    display_pause_help(window, text, position);
}
