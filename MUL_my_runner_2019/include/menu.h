/*
** EPITECH PROJECT, 2019
** menu_h
** File description:
** menu_h
*/

#ifndef MENU_H
#define MENU_H

typedef struct menu_s
{
    sfSprite *menu_spr;
    sfTexture *menu_tex;
    sfSprite *but_inf_spr;
    sfTexture *but_inf_tex;
    sfSprite *but_play_spr;
    sfTexture *but_play_tex;
    sfSprite *but_quit_spr;
    sfTexture *but_quit_tex;
    sfIntRect button_rect;
    sfVector2f pos_play;
    sfVector2f pos_quit;
    sfVector2f pos_inf;
}menu_t;

menu_t display_menu(menu_t menu);
void destroy_menu(menu_t menu);
void display_screen(menu_t menu, game_t game);

#endif
