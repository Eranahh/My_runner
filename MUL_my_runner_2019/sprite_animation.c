/*
** EPITECH PROJECT, 2019
** sprite_animation
** File description:
** sprite_animation
*/

#include "my.h"

sprite_t sprite_data(sprite_t spr)
{
    spr.change = 0;
    spr.jump = 0;
    spr.vit = 20;
    spr.n = 0;
    spr.hit = 0;
    spr.pos.x = -300;
    spr.pos.y = 600;
    spr.rect.top = 0;
    spr.rect.left = 0;
    spr.rect.width = 119;
    spr.rect.height = 105;
    return (spr);
}

sprite_t display_sprite(sfRenderWindow *window)
{
    sprite_t spr;

    spr.check = 0;
    spr = sprite_data(spr);
    spr.sprite = sfSprite_create();
    spr.texture = sfTexture_createFromFile("assets/char/fifteen2.png", NULL);
    sfSprite_setTexture(spr.sprite, spr.texture, sfTrue);
    sfRenderWindow_drawSprite(window, spr.sprite, NULL);
    sfSprite_setPosition(spr.sprite, spr.pos);
    return (spr);
}

void sprite_move(game_t game, sprite_t *spr, text_t *text)
{
    clock_work(spr, game, text);
    if (spr->jump == 1)
        jump_up(&game, spr);
}

void jump_char(sprite_t *spr)
{
    if (spr->pos.y >= 350 && spr->pos.y <= 600 && spr->vit != -20) {
        spr->rect.top = 105;
        spr->pos.y = spr->pos.y - spr->vit;
        spr->vit--;
    }
    if (spr->vit <= -20) {
        spr->vit = 20;
        spr->pos.y = 600;
        spr->rect.top = 0;
        spr->jump = 0;
    }
}

void jump_up(game_t *game, sprite_t *spr)
{
    game->time_j = sfClock_getElapsedTime(game->clock_j);
    if (game->time_j.microseconds > 10000) {
        jump_char(spr);
        sfClock_restart(game->clock_j);
    }
    sfSprite_setPosition(spr->sprite, spr->pos);
    sfSprite_setTextureRect(spr->sprite, spr->rect);
    sfRenderWindow_drawSprite(game->window, spr->sprite, NULL);
}
