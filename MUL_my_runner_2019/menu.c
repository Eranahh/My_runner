/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#include "include/my.h"

void destroy_menu(menu_t menu)
{
    sfSprite_destroy(menu.menu_spr);
    sfSprite_destroy(menu.but_play_spr);
    sfSprite_destroy(menu.but_quit_spr);
    sfSprite_destroy(menu.but_inf_spr);
    sfTexture_destroy(menu.menu_tex);
    sfTexture_destroy(menu.but_play_tex);
    sfTexture_destroy(menu.but_quit_tex);
    sfTexture_destroy(menu.but_inf_tex);
}

menu_t menu_data(menu_t menu)
{
    menu.button_rect.top = 0;
    menu.button_rect.left = 0;
    menu.button_rect.width = 200;
    menu.button_rect.height = 70;
    menu.pos_play.x = 15;
    menu.pos_play.y = 350;
    menu.pos_inf.x = 15;
    menu.pos_inf.y = 450;
    menu.pos_quit.x = 15;
    menu.pos_quit.y = 550;
    menu.menu_tex = sfTexture_createFromFile("assets/menu/menubg2.png", NULL);
    menu.menu_spr = sfSprite_create();
    sfSprite_setTexture(menu.menu_spr, menu.menu_tex, sfTrue);
    return (menu);
}

menu_t menu_button(menu_t menu)
{
    menu.but_play_tex = sfTexture_createFromFile("assets/menu/mapped.png", NULL);
    menu.but_quit_tex = sfTexture_createFromFile("assets/menu/quit.png", NULL);
    menu.but_inf_tex = sfTexture_createFromFile("assets/menu/infin.png", NULL);
    menu.but_play_spr = sfSprite_create();
    menu.but_quit_spr = sfSprite_create();
    menu.but_inf_spr = sfSprite_create();
    return (menu);
}

void display_screen(menu_t menu, game_t game)
{
    sfRenderWindow_drawSprite(game.window, menu.menu_spr, NULL);
    sfSprite_setTexture(menu.menu_spr, menu.menu_tex, sfTrue);
    sfSprite_setTexture(menu.but_play_spr, menu.but_play_tex, sfTrue);
    sfSprite_setTexture(menu.but_quit_spr, menu.but_quit_tex, sfTrue);
    sfSprite_setTexture(menu.but_inf_spr, menu.but_inf_tex, sfTrue);
    sfRenderWindow_drawSprite(game.window, menu.but_play_spr, NULL);
    sfRenderWindow_drawSprite(game.window, menu.but_quit_spr, NULL);
    sfRenderWindow_drawSprite(game.window, menu.but_inf_spr, NULL);
    sfSprite_setPosition(menu.but_play_spr, menu.pos_play);
    sfSprite_setPosition(menu.but_quit_spr, menu.pos_quit);
    sfSprite_setPosition(menu.but_inf_spr, menu.pos_inf);
}

menu_t display_menu(menu_t menu)
{
    menu = menu_data(menu);
    menu = menu_button(menu);
    return (menu);
}
