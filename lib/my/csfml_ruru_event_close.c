/*
** EPITECH PROJECT, 2021
** create window
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

void ruru_event_close(sfRenderWindow* window, sfEvent event)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape) ){
        sfRenderWindow_close(window);
    }
    return;
}
