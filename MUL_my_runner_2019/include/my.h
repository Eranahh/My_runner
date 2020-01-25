/*
** EPITECH PROJECT, 2018
** my
** File description:
** include and prototype
*/

#ifndef MY_H
#define MY_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include "game.h"
#include "mouse_button_event.h"
#include "sprite.h"
#include "background.h"
#include "menu.h"
#include "music.h"
#include "text.h"
#include "map.h"
#include "end.h"

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strdup(char const *src);
void my_putchar(char c);
int my_putstr(char const *str);
void lauch_game(game_t game, sprite_t spr, char *file);
void destroy_game(game_t game, sprite_t spr, background_t *bg, m_t play);
void destroy_other(text_t text);

enum e_state {
    MENU = 0,
    GAME
};

#endif
