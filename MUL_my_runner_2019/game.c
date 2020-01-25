/*
** EPITECH PROJECT, 2019
** open_windiow
** File description:
** open_windiow
*/

#include "my.h"

game_t display_window(game_t game)
{
    game.state = 1;
    game.n = 0;
    game.mode.width = 1280;
    game.mode.height = 769;
    game.mode.bitsPerPixel = 32;
    game.window = sfRenderWindow_create(game.mode, "my_window", sfResize |
        sfClose, NULL);
    return (game);
}

void game_loop(game_t g, menu_t menu, background_t *bg, sprite_t *spr, map_t *m, m_t *p)
{
    if (g.state == 1) {
        display_screen(menu, g);
        move_sprite(spr);
        p->check = 0;
    }
    else if (g.state == 2) {
        launch_music(p);
        bg = parallax_scrolling(g, bg);
        map_draw(g, m);
        get_back(spr);
    }
    else if (g.state == 3) {
        launch_music(p);
        bg = parallax_scrolling(g, bg);
        get_back(spr);
    }
}

void choose_state(background_t *bg, game_t game, sprite_t spr, map_t *map)
{
    text_t text;
    menu_t menu;
    m_t play;

    play = music_play(play);
    menu = display_menu(menu);
    text = text_data(text);
    while (sfRenderWindow_isOpen(game.window)) {
        my_event(&game, &spr, &menu);
        sfRenderWindow_clear(game.window, sfBlack);
        game_loop(game, menu, bg, &spr, map, &play);
        sprite_move(game, &spr, &text);
        if (game.state == 2 || game.state == 3)
            text = score_display(game, text);
        sfRenderWindow_display(game.window);
    }
    destroy_game(game, spr, bg, play);
    destroy_menu(menu);
    destroy_other(text);
}

void lauch_game(game_t game, sprite_t spr, char *file)
{
    background_t *bg = NULL;
    map_t *map = NULL;

    game.sp_clock = sfClock_create();
    game.clock = sfClock_create();
    game.clock_j = sfClock_create();
    game.clock_map = sfClock_create();
    game = display_window(game);
    sfRenderWindow_setFramerateLimit(game.window, 60);
    bg = display_background(bg);
    map = map_creation(find_obs(file), file);
    spr = display_sprite(game.window);
    choose_state(bg, game, spr, map);
}
