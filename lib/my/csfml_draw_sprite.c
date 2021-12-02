/*
** EPITECH PROJECT, 2021
** create window
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdarg.h>

void ruru_draw_sprite(sfRenderWindow* window, int nombre_de_sprite, ...)
{
    va_list args;
    va_start(args, nombre_de_sprite);
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < nombre_de_sprite; i++){
        sfSprite* sprite = va_arg(args, sfSprite*);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    sfRenderWindow_display(window);
}
