/*
** EPITECH PROJECT, 2019
** my_event
** File description:
** my_event
*/

#include "my.h"

int calculation(sfVector2i pos, menu_t menu)
{
    sfFloatRect play = sfSprite_getGlobalBounds(menu.but_play_spr);
    sfFloatRect quit = sfSprite_getGlobalBounds(menu.but_quit_spr);
    sfFloatRect inf = sfSprite_getGlobalBounds(menu.but_inf_spr);

    if (sfFloatRect_contains(&play, pos.x, pos.y) == sfTrue)
        return (1);
    else if (sfFloatRect_contains(&quit, pos.x, pos.y) == sfTrue)
        return (2);
    else if (sfFloatRect_contains(&inf, pos.x, pos.y) == sfTrue)
        return (3);
    return (0);
}

void collision(game_t *game, menu_t *menu)
{
    sfVector2i res = sfMouse_getPositionRenderWindow(game->window);

    if (calculation(res, *menu) == 1)
        game->state = 2;
    else if (calculation(res, *menu) == 2)
        game->state = 0;
    else if (calculation(res, *menu) == 3)
        game->state = 3;
}

void mouse_click(game_t *game, menu_t *menu)
{
    if (game->event.type == sfEvtMouseButtonPressed) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            collision(game, menu);
        }
    }
}

void my_event(game_t *ga, sprite_t *s, menu_t *me)
{
    while (sfRenderWindow_pollEvent(ga->window, &ga->event)) {
        if (ga->state != 2 && ga->state != 3 &&
            (ga->event.type == sfEvtClosed ||
            ga->event.key.code == sfKeyQ || ga->state == 0))
            sfRenderWindow_close(ga->window);
        if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
            s->jump = 1;
        if (ga->state == 1)
            mouse_click(ga, me);
        if ((ga->state == 2 || ga->state == 3) &&
            sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            ga->state = 1;
    }
}
