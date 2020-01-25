/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** sprite data
*/

#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.h>
#include "game.h"

typedef struct background_s background_t;

typedef struct menu_s menu_t;

typedef struct sprite_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int change;
    int check;
    int hit;
    int n;
    int vit;
    int jump;
    sfVector2f pos;
    sfVector2f d_pos;
}sprite_t;

sprite_t display_sprite(sfRenderWindow *window);
void move_sprite(sprite_t *spr);
void clock_work(sprite_t *spr, game_t game, text_t *text);
void collision(game_t *game, menu_t *menu);
void check_death_rect(sprite_t *spr);
game_t death_animation(sprite_t *spr, game_t game);
void jump_char(sprite_t *spr);
void jump_up(game_t *game, sprite_t *spr);
void get_back(sprite_t *spr);
void sprite_move(game_t game, sprite_t *spr, text_t *text);

#endif
