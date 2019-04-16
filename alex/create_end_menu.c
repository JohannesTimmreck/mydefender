/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** create_end_menu
*/

#include "defender.h"

visual_t *create_visual(char *file, sfVector2f pos)
{
    visual_t *visual = malloc(sizeof(visual_t));

    visual->sprite = sfSprite_create();
    visual->position = pos;
    visual->texture = sfTexture_createFromFile(file, NULL);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, pos);
    return (visual);
}

end_t *create_result_and_stars(end_t *end, int amount)
{
    if (amount >= 0) {
        end->amount_stars = amount;
        end->result = 1;
    }
    if (amount < 0) {
        end->amount_stars = 0;
        end->result = 0;
    }
    return (end);
}

end_t *create_end(sfFont *font, int amount)
{
    sfVector2f position = create_vector(660, 600);
    end_t *end = malloc(sizeof(end_t));

    end = create_result_and_stars(end, amount);
    end->stars = create_visual(STAR, position);
    position = create_vector(610, 190);
    end->background = create_visual(PAUSE_MENU, position);
    position = create_vector(740, 325);
    end->text = create_text(sfYellow, 50, position, font);
    position = create_vector(740, 455);
    end->button_text = create_text(sfYellow, 35, position, font);
    position = create_vector(710, 425);
    end->back = create_button_menu(10, position);
    end->select = sfMusic_createFromFile(SELECT_SOUND);
    end->move = sfMusic_createFromFile(MOVE_SOUND);
    sfMusic_setVolume(end->select, 20);
    sfMusic_setVolume(end->move, 20);
    return (end);
}