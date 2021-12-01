/*
** EPITECH PROJECT, 2021
** create window
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfRenderWindow* ruru_create_window(int width, int height, int fps, sfBool full)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {width, height, 1};
    if (full == sfTrue){
        window = sfRenderWindow_create(video_mode, "<3",
        sfFullscreen | sfResize | sfClose, 0);
    } else {
        window = sfRenderWindow_create(video_mode, "<3",
        sfResize | sfClose, 0);
    }
    sfRenderWindow_setFramerateLimit(window, fps);
    return window;
}
