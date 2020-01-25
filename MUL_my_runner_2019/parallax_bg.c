/*
** EPITECH PROJECT, 2019
** parallax
** File description:
** parallax
*/

#include "my.h"

background_t bg_data(background_t bg, char *filepath)
{
    bg.turn = 10;
    bg.rect.top = 0;
    bg.rect.left = 0;
    bg.rect.width = 1280;
    bg.rect.height = 769;
    bg.bg_texture = sfTexture_createFromFile(filepath, NULL);
    sfTexture_setRepeated(bg.bg_texture, sfTrue);
    bg.bg_sprite = sfSprite_create();
    sfSprite_setTexture(bg.bg_sprite, bg.bg_texture, 0);
    return (bg);
}

background_t *init_background(void)
{
    background_t *bg = malloc(sizeof(*bg) * 7);

    bg[0] = bg_data(*bg, "assets/bg/runner(background_pack).png");
    bg[1] = bg_data(*bg, "assets/bg/runner(last).png");
    bg[2] = bg_data(*bg, "assets/bg/runner(between).png");
    bg[3] = bg_data(*bg, "assets/bg/runner(city_background2).png");
    bg[4] = bg_data(*bg, "assets/bg/runner(lights2).png");
    bg[5] = bg_data(*bg, "assets/bg/runner(city_front2).png");
    bg[6] = bg_data(*bg, "assets/bg/runner(road_foreground2).png");
    return (bg);
}

void display_bg(game_t game, background_t *bg)
{
    sfRenderWindow_drawSprite(game.window, bg[0].bg_sprite, NULL);
    sfRenderWindow_drawSprite(game.window, bg[1].bg_sprite, NULL);
    sfRenderWindow_drawSprite(game.window, bg[2].bg_sprite, NULL);
    sfRenderWindow_drawSprite(game.window, bg[3].bg_sprite, NULL);
    sfRenderWindow_drawSprite(game.window, bg[4].bg_sprite, NULL);
    sfRenderWindow_drawSprite(game.window, bg[5].bg_sprite, NULL);
    sfRenderWindow_drawSprite(game.window, bg[6].bg_sprite, NULL);
}

background_t *parallax_scrolling(game_t game, background_t *bg)
{
    display_bg(game, bg);
    bg[1].rect.left += 1;
    bg[2].rect.left += 3;
    bg[3].rect.left += 6;
    bg[4].rect.left += 9;
    bg[5].rect.left += 13;
    bg[6].rect.left += 18;
    sfSprite_setTextureRect(bg[1].bg_sprite, bg[1].rect);
    sfSprite_setTextureRect(bg[2].bg_sprite, bg[2].rect);
    sfSprite_setTextureRect(bg[3].bg_sprite, bg[3].rect);
    sfSprite_setTextureRect(bg[4].bg_sprite, bg[4].rect);
    sfSprite_setTextureRect(bg[5].bg_sprite, bg[5].rect);
    sfSprite_setTextureRect(bg[6].bg_sprite, bg[6].rect);
    return (bg);
}
