/*
** EPITECH PROJECT, 2019
** music_lauch
** File description:
** music_lauch
*/

#include "my.h"

m_t music_play(m_t play)
{
    play.music = sfMusic_createFromFile("music/pursuit.ogg");
    play.sound = sfMusic_createFromFile("music/confirm.ogg");
    sfMusic_setVolume(play.music, 33);
    sfMusic_setVolume(play.sound, 50);
    play.check = 0;
    return (play);
}

void launch_music(m_t *play)
{
    if (play->check == 0) {
        sfMusic_play(play->music);
        sfMusic_setLoop(play->music, sfTrue);
        sfMusic_play(play->sound);
        play->check = 1;
    }
}
