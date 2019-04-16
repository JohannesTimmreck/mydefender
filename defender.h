/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** headerfile
*/

#ifndef _DEFENDER_
#define _DEFENDER_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_LENGTH (10)
#define TILE_SIZE (100)
//DIRECTIONS
#define UP (0)
#define LEFT (1)
#define DOWN (2)
#define RIGHT (3)
//ENEMY_ANIMATIONS
#define ENEMY_FACE_U (0)
#define ENEMY_FACE_L (100)
#define ENEMY_FACE_D (200)
#define ENEMY_FACE_R (300)
#define ENEMY_WIDTH (100)
#define ENEMY_HEIGHT (100)
#define HEALTHBAR_WIDTH (95)
#define HEALTHBAR_HEIGHT (5)
#define WALK_SPRITES (8)
#define ATTACK_SPRITES (6)
#define ATTACK_LV2_SPRITES (8)
#define DYING_SPRITES (6)
//ENEMY_STATS
#define SPEED_LV1 (2)
#define SPEED_LV2 (1)
#define SPEED_LV3 (0.5)
#define HEALTH_LV1 (45)
#define HEALTH_LV2 (75)
#define HEALTH_LV3 (400)
#define DMG_LV1 (10)
#define DMG_LV2 (20)
#define DMG_LV3 (30)
#define REWARD_LV1 (25)
#define REWARD_LV2 (50)
#define REWARD_LV3 (100)
//ENEMY_STATUS
#define WALKING (0)
#define ATTACKING (1)
#define DYING (2)
#define DEAD (3)
#define WAITING (4)
//ENEMY_PATHS
#define LV1_WALK ("media/visual/enemies/lv1_walk.png")
#define LV1_ATTACK ("media/visual/enemies/lv1_attack.png")
#define LV1_DIE ("media/visual/enemies/lv1_die.png")
#define LV2_WALK ("media/visual/enemies/lv2_walk.png")
#define LV2_ATTACK ("media/visual/enemies/lv2_attack.png")
#define LV2_DIE ("media/visual/enemies/lv2_die.png")
#define LV3_WALK ("media/visual/enemies/lv3_walk.png")
#define LV3_ATTACK ("media/visual/enemies/lv3_attack.png")
#define LV3_DIE ("media/visual/enemies/lv3_die.png")
#define PATH_FULL_HEALTHBAR ("media/visual/enemies/full_healthbar.png")
#define PATH_EMPTY_HEALTHBAR ("media/visual/enemies/empty_healthbar.png")
//TILE_PATHS
#define PATH_TO_GRASS ("media/visual/tiles/grass.png")
#define PATH_TO_PATH ("media/visual/tiles/path.png")
#define PATH_TO_BUILD ("media/visual/tiles/build_place.png")
#define PATH_TO_START_UP ("media/visual/tiles/start_up.png")
#define PATH_TO_START_RIGHT ("media/visual/tiles/start_right.png")
#define PATH_TO_START_DOWN ("media/visual/tiles/start_down.png")
#define PATH_TO_START_LEFT ("media/visual/tiles/start_left.png")
#define PATH_CORN_DOWN_RIGHT ("media/visual/tiles/downright_corner.png")
#define PATH_CORN_RIGHT_UP ("media/visual/tiles/rightup_corner.png")
#define PATH_CORN_UP_LEFT ("media/visual/tiles/upleft_corner.png")
#define PATH_CORN_LEFT_DOWN ("media/visual/tiles/leftdown_corner.png")

//CASTLE
#define CASTLE_HEALTH (1000)
#define FULL_CASTLE_HB ("media/visual/castle/full_healthbar_castle.png")
#define EMPTY_CASTLE_HB ("media/visual/castle/empty_healthbar_castle.png")
#define CASTLE_PATH ("media/visual/castle/castle.png")

//Tower_paths
#define PATH_TO_MAGE ("media/visual/tower/mage_sheet.png")
#define PATH_TO_ARTILLERY ("media/visual/tower/artillery_sheet.png")
#define PATH_TO_ARCHER ("media/visual/tower/archer_sheet.png")
#define PATH_TO_ICE ("media/visual/tower/ice_sheet.png")
#define TOWEROFFSET (100)

//button_paths
#define BUILDOPTIONS ("media/visual/buttons/buildoptions.png")
#define BUILDSPACE ("media/visual/buttons/buildspace.png")
#define BUILDWHEEL ("media/visual/buttons/buildwheel.png")
#define UPGRADEWHEEL ("media/visual/buttons/upgradewheel.png")
#define INFOBOX ("media/visual/buttons/infobox.png")
#define PAUSE_BUTTON ("media/visual/buttons/pause_button.png")
#define SELECT_BUTTON ("media/visual/buttons/select_button.png")
#define ICONOFFSET (60)

//menu_paths
#define PAUSE_MENU ("media/visual/menu/pause_menu.png")
#define MAIN_MENU ("media/visual/menu/menu_background.jpg")
#define SELECT_MENU ("media/visual/menu/select_background.jpg")
#define HOW_TO_PLAY ("media/visual/menu/how_to_play.png")
#define STAR ("media/visual/menu/star.png")
#define FONT ("media/Pixeled.ttf")
#define LEVEL1 ("media/visual/menu/level1.png")
#define LEVEL2 ("media/visual/menu/level2.png")
#define LEVEL3 ("media/visual/menu/level3.png")

//projectile paths
#define HUNT_PROJ ("media/visual/tower/arrow.png")
#define ARTY_PROJ ("media/visual/tower/canon_ball.png")
#define MAGE_PROJ ("media/visual/tower/mage_proj.png")

//sounds
#define MOVE_SOUND ("media/sounds/menu/move.ogg")
#define SELECT_SOUND ("media/sounds/menu/select.ogg")
#define WAITING_SOUND ("media/sounds/menu/waiting.ogg")
#define GAME_SOUND ("media/sounds/game/game.ogg")
//tower sounds
#define BUILD_SOUND ("media/sounds/game/build_sound.ogg")
#define ARCH_SOUND ("media/sounds/game/arrow_sound.ogg")
#define ARTY_SOUND ("media/sounds/game/canon_sound.ogg")
#define MAGE_SOUND ("media/sounds/game/mage_sound.ogg")

struct visual {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect animrect;
    sfIntRect hitbox;
};
typedef struct visual visual_t;

struct towerstats {
    int atk;
    int magic;
    float spd;
    int range;
    int cost;
    int refund;
    sfClock *clock;
};
typedef struct towerstats tstats_t;

struct button {
    int type;
    sfBool hover;
    visual_t *visual;
    struct button *next;
};
typedef struct button button_t;

typedef struct projectile_s projectile_t;
struct projectile_s
{
    sfClock *clock;
    int restart;
    sfVector2f target;
    int damage;
    visual_t *visual;
    projectile_t *next;
};

typedef struct buildspace space_t;
struct buildspace {
    int buildon;
    sfMusic *build;
    sfMusic *shoot;
    sfBool attack;
    sfBool atk_ready;
    sfBool options_active;
    visual_t *visual;
    int towertype;
    int level;
    tstats_t *towerstats;
    space_t *next;
    visual_t *buildwheel;
    button_t *buildoptions;
    visual_t *upgradewheel;
    button_t *upgradeoptions;
    projectile_t *projectile;
};

struct menu {
    sfMusic *select;
    sfMusic *move;
    int active;
    sfRectangleShape *rect;
    visual_t *background;
    sfText *text;
    button_t *options;
};
typedef struct menu menu_t;

struct game_over {
    sfMusic *select;
    sfMusic *move;
    int amount_stars;
    int result;
    visual_t *stars;
    visual_t *background;
    sfText *text;
    sfText *button_text;
    button_t *back;
};
typedef struct game_over end_t;

struct select_screen {
    sfMusic *select;
    sfMusic *move;
    visual_t *one;
    visual_t *two;
    visual_t *three;
    visual_t *background;
    visual_t *star;
    sfText *name;
    button_t *level;
};
typedef struct select_screen select_t;

struct tiles_s
{
    int type;
    visual_t *visual;
    struct tiles_s *next;
};
typedef struct tiles_s tiles_t;

typedef struct healthbar_s healthbar_t;
struct healthbar_s
{
    visual_t *curr;
    visual_t *empty;
};

struct castle_s
{
    visual_t *visual;
    int max_health;
    int health;
    healthbar_t *healthbar;
};
typedef struct castle_s castle_t;

struct map_s
{
    sfVector2f start_position;
    int start_direction;
    int num_of_towers;
    char **map;
    tiles_t *tile_list;
    castle_t *castle;
    sfBool map_correct;
};
typedef struct map_s map_t;

typedef struct enemy_stats_s enemy_stats_t;
struct enemy_stats_s
{
    unsigned int level;
    int health;
    unsigned int max_health;
    float speed;
    unsigned int dmg;
    unsigned int reward;
};

typedef struct enemy_s enemy_t;
struct enemy_s
{
    int direction;
    int status;
    sfBool attacked;
    sfVector2f center_point;
    visual_t *vs;
    int anim_sprite;
    sfBool slowed;
    enemy_stats_t *stats;
    healthbar_t *hb;
    enemy_t *next;
};

typedef struct enemy_wave_s enemy_wave_t;
struct enemy_wave_s
{
    sfBool spawned;
    unsigned int wave_num;
    enemy_t *enemy_list;
    enemy_wave_t *next;
};

struct enemy_info_s
{
    enemy_wave_t *enemy_waves;
    sfClock *movement_clock;
    sfClock *anim_clock;
    sfClock *spawn_clock;

};
typedef struct enemy_info_s enemy_info_t;

struct game_loop_s
{
    sfFont *font;
    sfText *amount;
    sfMusic *music;
    sfEvent *event;
    space_t *space;
    int value;
};
typedef struct game_loop_s gp_t;

int my_getnbr(char *str);
char **split_str(char *str, char split);


void destroy_select(select_t *select);
void destroy_menu(menu_t *menu, int pause);
void destroy_how_to(sfFont *f, sfText *t, sfSprite *s);
void destroy_end(end_t *end);
void destroy_buildspace(space_t *space);
button_t *destroy_buttons(button_t *button);
void destroy_visual(visual_t *visual);

//create_destroy_draw_manage_main.c
gp_t *create_gameloop(map_t *map, enemy_info_t *enemy_info);
void destroy_mainloop(gp_t *gp);
void draw_main_loop(sfRenderWindow *window, enemy_info_t *enemy_info,
    space_t *space, map_t *map);
void manage_mainloop(sfRenderWindow *window, enemy_info_t *enemy_info,
    map_t *map, gp_t *gp);
int check_for_player_exit(sfRenderWindow *window, gp_t *g);

//manage_highscore.c
void check_for_new_highscore(int amount, int map);
char *get_highscore(void);

//create_selection.c
select_t *create_selection(sfFont *font);

//manage_selection_event.c
int manage_selection(sfRenderWindow *window, sfEvent *event, select_t *select);

//select_map_to_play.c
int select_map_to_play(sfRenderWindow *window);
char *get_highscore(void);

//create_end_menu.c
end_t *create_end(sfFont *font, int amount);
visual_t *create_visual(char *file, sfVector2f pos);

//manage_end_menu.c
int manage_end_input(sfRenderWindow *window, sfEvent *event, end_t *end);

//end_menu.c
int game_ends(sfRenderWindow *window, int game_state, int map);

//check_for_end.c
int end_the_game(sfRenderWindow *w, map_t *m,  enemy_info_t *e, int map);

//create_main_menu.c
int create_main_menu(sfRenderWindow *window);

//main_menu.c
void display_menu(sfRenderWindow *window, menu_t *menu);
int manage_main_event(sfRenderWindow *window, sfEvent *event, menu_t *main);
void how_to_play(sfRenderWindow *window);
void display_help(sfRenderWindow *window, sfText *text, sfVector2f position);

//manage_gold.c
int upddate_player_money(int gp, space_t *space, button_t *clicked);

//create_button.c
button_t *create_button(int type, sfVector2f vector);
button_t *add_to_last_button(button_t *list, button_t *next);

//create_buildoptions.c
sfVector2f create_vector(int x, int y);
button_t *create_buildoptions(sfVector2f vector);
button_t *create_upgradeoptions(sfVector2f vector);
button_t *add_to_last_button(button_t *list, button_t *next);

//create_buildspace.c
space_t *create_space(sfVector2f position);

//create_buildspace_list.c
space_t *create_buildspace(char **map);

//animate_tower.c
void animate_tower(space_t *space);

//create_info_text.c
void save_information(sfRenderWindow *w, button_t *opt, space_t *space,
    int mod);
sfText *create_text(sfColor color, int size, sfVector2f pos, sfFont *font);

//assign_info_text.c
char *assign_title(int type, space_t *space);
char *assign_text_build(int type);
char *get_upgrade_1_type(int type);
char *get_upgrade_2_type(int type);

//display_button_and_spaces.c
void display_buildspaces(sfRenderWindow *window, space_t *space);

//player_management.c
int event_management(sfRenderWindow *window, sfEvent *event, space_t *space,
    int gp);

//space_management.c
int check_space_release(sfMouseButtonEvent mouse, space_t *space, int gp);
void check_click_options_space(sfMouseButtonEvent mouse, space_t *space);
void check_space_position(sfMouseMoveEvent mouse, space_t *space);

//button_management.c
void check_button_positon(sfMouseMoveEvent m, button_t *options);
void check_click_options_button(sfMouseButtonEvent m, button_t *options);
int check_button_release(sfMouseButtonEvent m, button_t *b, space_t *s, int gp);
void release_button_effect(space_t *space, button_t *clicked);

//build_tower.c
tstats_t *assign_stats(int type);
void assign_sound(space_t *space, int type);
void assign_sprite(space_t *space, int type);
tstats_t *update_towerstats(int type, int atk, int spd, int range);
void change_space(char *filename, visual_t *visual);

//upgrade_or_sell_tower.c
void sell_tower(space_t *space);
void upgrade_tier_two(space_t *space);
void upgrade_tier_one(space_t *space);
void upgrade_towerstats(space_t *space, int atk, int spd, int range);

//create_pause.c
menu_t *create_pause(sfFont *font);
visual_t *create_menu_button_visual(sfVector2f vector);
button_t *create_button_menu(int type, sfVector2f vector);
button_t *create_menu_options(sfVector2f pos);

//pause_menu.c
int do_a_pause(sfRenderWindow *window);

//manage_pause_and_menu_event.c
void check_menu_position(sfMouseMoveEvent mouse, button_t *options,
    sfMusic *music);
void check_menu_click(sfMouseButtonEvent mouse, button_t *options,
    sfMusic *music);
int manage_pause_event(sfRenderWindow *window, sfEvent *event, menu_t *pause);
void put_space_into_hover(sfMouseMoveEvent m, button_t *t, sfMusic *music);

//create_window.c
sfRenderWindow *create_window(unsigned int width, unsigned int height);

//combine_strings
char *combine_strings(char *one, char *two);

//my_int_to_string
char *my_int_to_str(int nb);

//tiles.c
tiles_t *add_to_list(tiles_t *list, tiles_t *new);
tiles_t *create_tile_list(char **map);
void destroy_tile_list(tiles_t *tile_list);

//create_tile.c
visual_t *create_tile_visual(char *path_to_texture, sfVector2f pos,
    sfVector2f size);
tiles_t *create_tile_list_entry(int type, sfVector2f pos);
void set_tile(tiles_t *tile, char type, char *texture_path, sfVector2f pos);

//map_path_error.c
void path_error(map_t *map, int sign);

//map_start_pos.c
void det_enemy_start_x(map_t *map);
void det_enemy_start(map_t *map);
void set_enemy_spawn_point(map_t *map);
void get_map_start(map_t *map);

//load_map.c
sfVector2f get_castle_pos(tiles_t *tile_list);
char **create_map(FILE *map_stream);
map_t *load_map(char *file_path);
void draw_map(map_t *map, sfRenderWindow *window);
void destroy_map(map_t *map);

//load_waves.c
char *get_wave_information(FILE *enemy_stream);
int get_num_of_waves(FILE *enemy_stream);
enemy_wave_t *create_new_wave(int current_wave, FILE *enemy_stream);
enemy_wave_t *link_waves(enemy_wave_t *list, enemy_wave_t *new);
enemy_wave_t *load_enemy_waves(char *file_path);

//load_enemy_visual.c
visual_t *create_enemy_visual(int level);
healthbar_t *create_healthbar(void);

//load_enemies.c
enemy_stats_t *create_enemy_stats(int level);
enemy_t *create_enemy(int level);
enemy_t *link_enemies(enemy_t *list, enemy_t *new);
enemy_t *create_enemy_list(char *wave_info);

//start_tile.c
void set_start_tile(visual_t *start, int direction);
void find_start_tile(tiles_t *tiles, int direction);

//start_wave.c
void spawn_next_wave(enemy_wave_t *enemy_waves, map_t *map);
sfIntRect set_start_anim(int direction);
void let_enemy_start(enemy_t *enemies, sfClock *spawn_clock);
void spawn_enemies(sfVector2f spawn_position, int direction,
    enemy_wave_t *enemies);

//move_waves.c
sfVector2f set_movement_offset(int direction, float speed);
void move_enemy_in_direction(enemy_t *enemy);
void move_wave(enemy_wave_t *enemies);
void move_enemy_waves(enemy_t *enemies, sfClock *movement_clock);

//draw_waves.c
void draw_wave(sfRenderWindow *window, enemy_wave_t *enemies);
void draw_waves(sfRenderWindow *window, enemy_wave_t *waves);

//rect.c
sfIntRect create_rect(int top, int left, int height, int width);
sfIntRect create_intrect(sfVector2f pos, sfVector2f size);
void move_rect(sfIntRect *rect, sfVector2f offset);
void move_rect_to(sfIntRect *rect, sfVector2f new_pos, sfVector2f bottom_left);

//enemy_view.c
void check_corner_direction(enemy_t *enemy, tiles_t *tile_list);
void enemy_check_for_corner(enemy_t *enemy, tiles_t *tile_list);
void enemy_check_for_wall(enemy_t *enemy, tiles_t *tile_list);
void enemy_list_change_movement(enemy_t *wave, tiles_t *tile_list);

//view_utilis.c
sfVector2f get_view(sfVector2f pos, int direction);
sfBool check_tile(enemy_t *enemy, tiles_t *tile_list, int direction);

//enemy_animation.c
void change_animation_direction(enemy_t *enemy);
void walking_animation(enemy_t *enemy);
void animate_enemy(enemy_t *enemy);
void animate_wave(enemy_wave_t *enemies);
void animate_enemies(enemy_t *enemies, sfClock *anim_clock);

//attack_animation.c
void set_attack_animtaion(enemy_t *enemy);
sfBool check_for_attack_end(enemy_t *enemy);
void reset_attack_anim(enemy_t *enemy);
void attacking_animation(enemy_t *enemy);

//enemy_handling.c
void start_enemies(enemy_info_t *enemy_info, map_t *map);
void manange_waves(enemy_info_t *enemy_info, map_t *map, int *gold);
enemy_info_t *init_enemy_info(char *path_to_waves);
void check_for_clock_restart(enemy_info_t *enemy_info, map_t *map);

//handle_healthbaer.c
void adjust_healthbar(visual_t *healthbar, int health, int max_health);
void enemies_adjust_health(enemy_t *enemies);
void let_enemies_die(enemy_t *enemies, int *gold);
void handle_castle_healthbar(enemy_t *enemies, castle_t *castle);

//castle.c
visual_t *set_healthbar_visual(char *path, sfVector2f pos, sfVector2f size);
healthbar_t *create_castle_healthbar(sfVector2f pos);
visual_t *create_castle_visual(sfVector2f pos);
castle_t *create_castle(tiles_t *tile_list);
void draw_castle(sfRenderWindow *window, castle_t *castle);

//johannes_utils.c
void free_arr(char **arr);
sfBool check_for_number(char *str);
sfVector2f create_vectorf(float x, float y);

//check_enemies_alive.c
sfBool check_enemies_alive(enemy_t *enemy_list);
sfBool check_wave_alive(enemy_wave_t *waves);

//destroy_enemies.c
void destroy_wave(enemy_wave_t *wave);
void destroy_enemy_info(enemy_info_t *enemy_info);

//create_sound.c
sfMusic *create_sound(char *path, int volume, sfBool loop);

//tower_shot.c
float calculate_distance_from_circle(sfVector2f circle_pos,
    sfVector2f enemy_pos);
float get_value(sfVector2f vect);
sfBool enemy_in_range(space_t *tower, enemy_t *enemies);
void tower_check_waves(space_t *tower, enemy_wave_t *waves);
void tower_aim(space_t *tower_list, enemy_wave_t *waves);

//tower_damage.c
void add_single_dmg(space_t *tower, int *enemy_health);
void apply_arty_dmg(projectile_t *projectile, enemy_t *e);
void apply_arty_dmg_list(projectile_t *projectile, enemy_wave_t *waves,
    int type);
void slow_wave(space_t *tower, enemy_t *enemies);

//projectile_movement.c
void move_projectile(projectile_t *projectile);
void tower_projectile_movement(space_t *tower);
projectile_t *stop_projectile(projectile_t *projectile, int type,
    enemy_wave_t *waves);
void tower_projectile_stop(space_t *tower, enemy_wave_t *waves);

//projectile.c
void rotate_sprite(projectile_t *projectile);
projectile_t *init_projectile(int type, sfVector2f pos, sfVector2f target,
    int damage);
projectile_t *add_projectile(projectile_t *list, projectile_t *new);
void free_projectile(projectile_t *projectile);
void free_projectile_list(projectile_t *projectile);

sfVector2f get_position(sfSprite *sprite);
#endif