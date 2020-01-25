/*
** EPITECH PROJECT, 2020
** end_data
** File description:
** end_data
*/

#include "my.h"

end_t end_data(end_t end, char *filepath)
{
    end.rect.top = 0;
    end.rect.left = 0;
    end.rect.width = 435;
    end.rect.height = 91;
    end.pos.x = 415;
    end.pos.y = -300;
    end.end_tex = sfTexture_createFromFile(filepath, NULL);
    sfTexture_setRepeated(end.end_tex, sfTrue);
    end.end_spr = sfSprite_create();
    sfSprite_setTexture(end.end_spr, end.end_tex, 0);
    return (end);
}

end_t *init_end(void)
{
    end_t *end = malloc(sizeof(*end) * 2);

    end[0] = end_data(*end, "assets/map/win.png");
    end[1] = end_data(*end, "assets/map/lose.png");
    return (end);
}

void draw_end(game_t game, end_t *end)
{
    sfRenderWindow_drawSprite(game.window, end[0].end_spr, NULL);
    sfRenderWindow_drawSprite(game.window, end[1].end_spr, NULL);
}

end_t *display_end(game_t game, end_t *end)
{
    draw_end(game, end);
    sfSprite_setTextureRect(end[0].end_spr, end[0].rect);
    sfSprite_setTextureRect(end[1].end_spr, end[1].rect);
    sfSprite_setPosition(end[0].end_spr, end[0].pos);
    sfSprite_setPosition(end[1].end_spr, end[1].pos);
    return (end);
}
