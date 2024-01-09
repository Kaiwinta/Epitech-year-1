/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Contain all the prototypes of all the function exposed by my libmy.a
*/

#ifndef MY_

    #define MY_

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Audio.h>

typedef struct sprite_list {
    int boosted;
    int size_ratio;
    int y_vel;
    int x_vel;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f vect;
    sfVector2f scale;
    struct sprite_list *next;
} sprite_list;

typedef struct game_stat {
    char mode;
    int nb_ghost;
    int nb_click;
    int nb_touch;
    int size;
    int max_speed;
    int nb_dead;
    struct my_window_t *window;
} game_stat;

typedef struct text {
    sfText *str;
    char *src_text;
    int x;
    int y;
    struct text *next;
}text;

typedef struct my_window_t {
    sfTexture *bg_text;
    sfSprite *bg_sprite;
    sfSoundBuffer *dead_buffer;
    sfSound *dead_sound;
    sfSoundBuffer *shoot_buffer;
    sfSound *shoot_sound;
    sfSoundBuffer *heal_buffer;
    sfSound *heal_sound;
    sfSoundBuffer *music_buffer;
    sfSound *music_sound;
    sfFont *font;
    struct text *t_list;
    struct text *load_list;
    struct text *end_list;
    struct text *wave;
    int total_aim;
    int is_loaded;
}my_window_t;

int display_help(void);
text *init_t_list(void);
int flag_game(char type);
sfIntRect init_rect(void);
my_window_t *init_window(void);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char const *src);
void check_ended(game_stat *stat);
void move_rec(sprite_list *s_list);
void move_vec(sprite_list *s_list);
void init_sprite(sprite_list *temp);
void update_all_text(game_stat *stat);
void update_vect(sprite_list *s_list);
void update_text_aim(game_stat *stat);
void go_random_dir(sprite_list *s_list);
void update_text_remain(game_stat *stat);
void update_rotation(sprite_list *s_list);
void update_rotation(sprite_list *s_list);
void move_vec_xtreme(sprite_list *s_list);
void update_mode(text *t_list, char *temp);
sfVector2f update_scale(sprite_list *s_list);
int my_strcmp(char const *s1, char const *s2);
int free_main(text *t_list, my_window_t *screen);
int free_all(sprite_list **s_list, game_stat *stat);
void add_boss(sprite_list **s_list, game_stat *stat);
void update_text_wave(my_window_t *window, int wave);
void update_aim(game_stat *stat, my_window_t *screen);
void add_in_list(sprite_list **s_list, game_stat *stat);
void update_boss_life(text *t_list, sprite_list *s_list);
int boss_easy(sfRenderWindow *window, my_window_t *screen);
int boss_hard(sfRenderWindow *window, my_window_t *screen);
void display_bg(sfRenderWindow *window, my_window_t *screen);
int boss_normal(sfRenderWindow *window, my_window_t *screen);
int boss_extreme(sfRenderWindow *window, my_window_t *screen);
void manage_touched_hard(sprite_list *s_list, game_stat *stat);
void add_in_text_list(text **t_list, int x, int y, char *word);
void manage_touched_easy(sprite_list *s_list, game_stat *stat);
void display_ghost(sfRenderWindow *window, sprite_list *s_list);
void easy(sfRenderWindow *window, int wave, my_window_t *screen);
int hard(sfRenderWindow *window, int wave, my_window_t *screen);
void manage_touched_normal(sprite_list *s_list, game_stat *stat);
void manage_touched_extreme(sprite_list *s_list, game_stat *stat);
int normal(sfRenderWindow *window, int wave, my_window_t *screen);
int extreme(sfRenderWindow *window, int wave, my_window_t *screen);
void manage_boss_touched_easy(sprite_list *s_list, game_stat *stat);
void manage_boss_touched_hard(sprite_list *s_list, game_stat *stat);
void manage_boss_touched_normal(sprite_list *s_list, game_stat *stat);
void end_screen(sfRenderWindow *window, int wave, my_window_t *screen);
void manage_boss_touched_extreme(sprite_list *s_list, game_stat *stat);
void loading_screen(sfRenderWindow *window, int wave, my_window_t *screen);
void restart(sfRenderWindow *window, char mode, int wave, my_window_t *screen);
void run_game(sfRenderWindow *window, sfClock *clock,
    sprite_list *s_list, game_stat *stat);
void analyse_events(sfRenderWindow *window, sfEvent *event,
    sprite_list *s_list, game_stat *stat);
void display_all_text(sfRenderWindow *window,
    text *t_list, sfFont *font);
void run_boss_game(sfRenderWindow *window, sfClock *clock,
    sprite_list *s_list, game_stat *stat);
void analyse_boss_events(sfRenderWindow *window, sfEvent *event,
    sprite_list *s_list, game_stat *stat);
#endif /* MY_ */
