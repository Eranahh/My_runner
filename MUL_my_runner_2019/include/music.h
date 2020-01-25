/*
** EPITECH PROJECT, 2019
** music
** File description:
** music
*/

#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Audio.h>

typedef struct music_s
{
    sfMusic *music;
    sfMusic *sound;
    int check;
}m_t;

m_t music_play(m_t play);
void launch_music(m_t *play);

#endif
