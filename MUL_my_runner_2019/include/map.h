/*
** EPITECH PROJECT, 2020
** map_h
** File description:
** map_h
*/

#ifndef MAP_H
#define MAP_H

typedef struct s_map
{
    sfTexture *map_tex;
    sfSprite *map_spr;
    sfIntRect rect;
    sfVector2f pos;
    char *file;
    int check;
    int lenght;
    int n;
    int c;
}map_t;

int find_obs(char *filepath);
map_t *map_creation(int nb, char *file);
void map_draw(game_t game, map_t *map);

#endif
