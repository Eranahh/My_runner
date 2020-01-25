/*
** EPITECH PROJECT, 2019
** game_h
** File description:
** game_h
*/

#ifndef GAME_H
#define GAME_H

#include <time.h>

typedef struct sprite_s sprite_t;

typedef struct background_s background_t;

typedef struct text_s text_t;

typedef struct menu_s menu_t;

typedef struct s_end end_t;

typedef struct s_map map_t;

typedef struct music_s m_t;

typedef struct game_s
{
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfClock *sp_clock;
    sfClock *clock_j;
    sfClock *clock_map;
    sfTime time_map;
    sfTime time_f;
    sfTime sp_time;
    sfTime time_j;
    int state;
    int n;
}game_t;

void my_event(game_t *ga, sprite_t *s, menu_t *me);
void help(void);

#endif
