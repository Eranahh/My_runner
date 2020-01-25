/*
** EPITECH PROJECT, 2020
** map_handling
** File description:
** map_handling
*/

#include "my.h"

int find_obs(char *filepath)
{
    int n = 0;
    int count = 0;

    while (filepath[n] != '\0') {
        if (filepath[n] == '1' || filepath[n] == '2')
            count++;
        n++;
    }
    return (count);
}

map_t map_data(map_t map, char *filepath, int place)
{
    map.n = 0;
    map.c = 0;
    map.check = 0;
    map.pos.x = place;
    map.pos.y = 550;
    map.rect.top = 0;
    map.rect.left = 0;
    map.rect.width = 100;
    map.rect.height = 150;
    map.map_tex = sfTexture_createFromFile(filepath, NULL);
    map.map_spr = sfSprite_create();
    sfSprite_setTexture(map.map_spr, map.map_tex, 0);
    return (map);
}

map_t *map_creation(int nb, char *file)
{
    int place = 2000;
    int c = 0;
    int lenght = 0;
    map_t *map = malloc(sizeof(*map) * nb);

    while (file[c] != '\0') {
        if (file[c] == '1') {
            map[lenght] = map_data(*map, "assets/map/obstacle.png", place);
            lenght++;
            place += 640;
        }
        if (file[c] == '0' || file[c] == ' ')
            place += 640;
        if (file[c] == '2') {
            map[lenght] = map_data(*map, "assets/map/end_line.png", place);
            map[lenght].pos.y = 350;
            lenght++;
            place += 1000;
        }
        c++;
    }
    (*map).lenght = lenght;
    return (map);
}

void map_draw(game_t game, map_t *map)
{
    int n = 0;

    while (n != map->lenght) {
        sfRenderWindow_drawSprite(game.window, map[n].map_spr, NULL);
        sfSprite_setTextureRect(map[n].map_spr, map[n].rect);
        map[n].pos.x -= 18;
        sfSprite_setPosition(map[n].map_spr, map[n].pos);
        n++;
    }
}
