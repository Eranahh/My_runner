/*
** EPITECH PROJECT, 2020
** end_game
** File description:
** end_game
*/

#ifndef END_H
#define END_H

typedef struct s_end
{
    sfSprite *end_spr;
    sfTexture *end_tex;
    sfIntRect rect;
    sfVector2f pos;
}end_t;

end_t *init_end(void);
end_t *display_end(game_t game, end_t *end);
int end_game(map_t *map, sprite_t *spr);
void lets_end(int res, end_t *end);

#endif
