/*
** EPITECH PROJECT, 2019
** background
** File description:
** background
*/

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <SFML/Graphics.h>

typedef struct background_s
{
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
    sfIntRect rect;
    float turn;
    float gl;
}background_t;

typedef struct s_list {
    struct background_s *bg;
    struct s_list *next;
}list_t;

void background_rectangle(game_t game, background_t *bg);
background_t *display_background(background_t *bg);
background_t *init_background(void);
background_t *parallax_scrolling(game_t game, background_t *bg);
void background_data(game_t game, list_t **list);

#endif
