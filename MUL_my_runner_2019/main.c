/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"

void help(void)
{
    my_putstr("Usage: ./my_runner [map]\n\n");
    my_putstr("VICE RUNNER\n\n");
    my_putstr("In menu: [~NO LIMIT~] = lauch the game in infinite mode\n");
    my_putstr("         [MAP] = lauch the game with the current loaded map\n");
    my_putstr("         [QUIT] = quit the game (or press Q on the keyboard)\n");
    my_putstr("\nIn map mode: Press Spacebar to jump and dodge the obstalces");
    my_putstr(" and run until the end\n\n");
    my_putstr("\nIn ~no limit~ mode: run to infinite and beyond..\n");
    my_putstr("Press escap to return to the menu\n\n");
    my_putstr("Note: the loaded map need to have only ONE line of obstacles ");
    my_putstr("and has to end with the numbers 20 to set the end\n\n");
    my_putstr("\nGood Luck and Have Fun :)\n");
}

char *read_map(char *file, char *map)
{
    int fd = open(file, O_RDWR);
    char buffer[256];
    int size_t = read(fd, &buffer, 256);

    (void)size_t;
    map = my_strdup(buffer);
    return (map);
}

int main(int ac, char **av)
{
    game_t game;
    sprite_t spr;
    char *map = NULL;

    if (ac == 1 || (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')) {
        help();
        return (1);
    }
    else if (ac == 2) {
        map = read_map(av[1], map);
        lauch_game(game, spr, map);
    }
    else
        return (84);
    return (0);
}
