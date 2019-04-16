/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "defender.h"

void rotate_sprite(projectile_t *projectile)
{
    sfVector2f y_axis = create_vectorf(0, 1);
    float denominator = get_value(projectile->target) * get_value(y_axis);
    float cosinus = projectile->target.y / denominator;
    float angle;
    if (projectile->target.x <= 0){
        angle = 180 + acos(cosinus) * (180 / M_PI);
    }else if (projectile->target.x > 0){
        angle = 180 - acos(cosinus) * (180 / M_PI);
    }
    sfSprite_rotate(projectile->visual->sprite, angle);
}

projectile_t *init_projectile(int type, sfVector2f pos, sfVector2f target,
    int damage)
{
    projectile_t *proj = malloc(sizeof(projectile_t));
    char *texture[] = {HUNT_PROJ, ARTY_PROJ, MAGE_PROJ};

    proj->next = NULL;
    proj->damage = damage;
    proj->target.x = target.x - pos.x;
    proj->target.y = target.y - pos.y;
    proj->visual = malloc(sizeof(visual_t));
    proj->visual->position.x = pos.x - 10;
    proj->visual->position.y = pos.y - 20;
    proj->visual->texture = sfTexture_createFromFile(texture[type - 1], NULL);
    proj->visual->sprite = sfSprite_create();
    proj->clock = sfClock_create();
    proj->restart = 0;
    if (type == 1)
        rotate_sprite(proj);
    sfSprite_setPosition(proj->visual->sprite, proj->visual->position);
    sfSprite_setTexture(proj->visual->sprite, proj->visual->texture, sfTrue);
    return (proj);
}

projectile_t *add_projectile(projectile_t *list, projectile_t *new)
{
    if (list == NULL)
        return (new);
    for (projectile_t *tmp = list; tmp != NULL; tmp = tmp->next) {
        if (tmp->next == NULL) {
            tmp->next = new;
            break;
        }
    }
    return (list);
}

void free_projectile(projectile_t *projectile)
{
    sfClock_destroy(projectile->clock);
    sfTexture_destroy(projectile->visual->texture);
    sfSprite_destroy(projectile->visual->sprite);
    free(projectile->visual);
    free(projectile);
}

void free_projectile_list(projectile_t *projectile)
{
    projectile_t *tmp;

    if (projectile == NULL)
        return;
    tmp = projectile->next;
    for (; projectile != NULL; projectile = tmp) {
        tmp = projectile->next;
        free(projectile);
    }
}