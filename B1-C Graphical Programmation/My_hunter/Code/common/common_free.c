/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** common_free.c
*/

#include "../include/my.h"

int free_text_list(text *t_list)
{
    text *temp = t_list;

    if (! temp)
        return 0;
    while (t_list != NULL) {
        temp = (t_list);
        (t_list) = t_list->next;
        free(temp->src_text);
        sfText_destroy(temp->str);
        free(temp);
    }
}

int free_main(text *t_list, my_window_t *screen)
{
    free_text_list(screen->t_list);
    free_text_list(screen->load_list);
    free_text_list(screen->wave);
    free_text_list(screen->end_list);
    sfSound_destroy(screen->shoot_sound);
    sfSound_destroy(screen->dead_sound);
    sfSound_destroy(screen->heal_sound);
    sfSound_destroy(screen->music_sound);
    sfSoundBuffer_destroy(screen->shoot_buffer);
    sfSoundBuffer_destroy(screen->dead_buffer);
    sfSoundBuffer_destroy(screen->music_buffer);
    sfSoundBuffer_destroy(screen->heal_buffer);
    sfFont_destroy(screen->font);
    sfSprite_destroy(screen->bg_sprite);
    sfTexture_destroy(screen->bg_text);
    free(screen);
    free_text_list(t_list);
}
