/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** visual_enemy
*/

#include "defender.h"

visual_t *create_enemy_visual(int level)
{
    char *texture_path[3] = {LV1_WALK, LV2_WALK, LV3_WALK};
    visual_t *visual = malloc(sizeof(visual_t));
    sfVector2f anim_pos = {0, 0};
    sfVector2f anim_size = {ENEMY_WIDTH, ENEMY_HEIGHT};

    visual->animrect = create_intrect(anim_pos, anim_size);
    visual->texture = sfTexture_createFromFile(texture_path[level - 1], NULL);
    visual->sprite = sfSprite_create();
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setTextureRect(visual->sprite, visual->animrect);
    return (visual);
}

healthbar_t *create_healthbar(void)
{
    healthbar_t *hb = malloc(sizeof(healthbar_t));
    sfVector2f anim_pos = {0, 0};
    sfVector2f anim_size = {HEALTHBAR_WIDTH, HEALTHBAR_HEIGHT};

    hb->curr = malloc(sizeof(visual_t));
    hb->empty = malloc(sizeof(visual_t));
    hb->curr->animrect = create_intrect(anim_pos, anim_size);
    hb->empty->animrect = create_intrect(anim_pos, anim_size);
    hb->curr->texture = sfTexture_createFromFile(PATH_FULL_HEALTHBAR, NULL);
    hb->empty->texture = sfTexture_createFromFile(PATH_EMPTY_HEALTHBAR, NULL);
    hb->curr->sprite = sfSprite_create();
    hb->empty->sprite = sfSprite_create();
    sfSprite_setTexture(hb->curr->sprite, hb->curr->texture, sfTrue);
    sfSprite_setTexture(hb->empty->sprite, hb->empty->texture, sfTrue);
    return (hb);
}
