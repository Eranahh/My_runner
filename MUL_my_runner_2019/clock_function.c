/*
** EPITECH PROJECT, 2019
** clock_function
** File description:
** clock_function
*/

#include "my.h"

void check_rect(sprite_t *spr)
{
    if (spr->rect.left >= 958)
        spr->check = 1;
    else if (spr->rect.left <= 0)
        spr->check = 0;
}

void move_sprite(sprite_t *spr)
{
    spr->pos.x += 7;
    if (spr->pos.x >= 3000)
        spr->pos.x = -200;
    sfSprite_setPosition(spr->sprite, spr->pos);
}

void get_back(sprite_t *spr)
{
    int vit = 30;

    if (spr->pos.x >= 1500)
        spr->pos.x = -200;
    if (spr->pos.x <= 5 || spr->pos.x >= 105) {
        if (spr->pos.x >= 20)
            spr->pos.x -= vit;
        else if (spr->pos.x <= 20)
            spr->pos.x += vit;
    }
    sfSprite_setPosition(spr->sprite, spr->pos);
    if (vit >= 10)
        vit--;
}

void clock_work(sprite_t *spr, game_t game, text_t *text)
{
    game.time_f = sfClock_getElapsedTime(game.clock);
    if (game.time_f.microseconds > 100000) {
        if (spr->check == 0)
            spr->rect.left += 119;
        else
            spr->rect.left = 0;
        if (game.state == 1) {
            text->nb = 0;
            move_sprite(spr);
        }
        if (game.state == 2 || game.state == 3)
            text->nb++;
        check_rect(spr);
        sfClock_restart(game.clock);
    }
    sfSprite_setTextureRect(spr->sprite, spr->rect);
    sfRenderWindow_drawSprite(game.window, spr->sprite, NULL);
}
