/*
** EPITECH PROJECT, 2019
** display_text
** File description:
** display_text
*/

#include "my.h"

text_t text_data(text_t text)
{
    text.nb = 0;
    text.pos.x = 1000;
    text.pos.y = 700;
    text.t_pos.x = 1160;
    text.t_pos.y = 700;
    text.font = sfFont_createFromFile("font/ARCADECLASSIC.TTF");
    text.t_font = sfFont_createFromFile("font/ARCADECLASSIC.TTF");
    text.score = sfText_create();
    text.t_score = sfText_create();
    text.str = malloc(sizeof(char) * 5);
    text.str[0] = '0';
    text.str[1] = '\0';
    text.str[2] = '\0';
    text.str[3] = '\0';
    text.str[4] = '\0';
    return (text);
}

char *get_score(char *res, int nb)
{
    int first = 0;
    int sec = 0;
    int i = 0;

    if (nb != 0)
        sec = nb;
    while (nb != 0) {
        sec = nb % 10;
        nb = nb / 10;
        first = sec;
        res[i] = first + 48;
        i++;
    }
    res[i] = '\0';
    res = my_revstr(res);
    return (res);
}

text_t score_display(game_t game, text_t text)
{
    text.str = get_score(text.str, text.nb);
    sfText_setFont(text.score, text.font);
    sfText_setFont(text.t_score, text.t_font);
    sfText_setCharacterSize(text.score, 50);
    sfText_setCharacterSize(text.t_score, 50);
    sfText_setPosition(text.score, text.pos);
    sfText_setPosition(text.t_score, text.t_pos);
    sfText_setString(text.score, " Score ");
    sfText_setString(text.t_score, text.str);
    sfRenderWindow_drawText(game.window, text.score, NULL);
    sfRenderWindow_drawText(game.window, text.t_score, NULL);
    return (text);
}
