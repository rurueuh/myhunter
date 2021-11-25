/*
** EPITECH PROJECT, 2021
** create window
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfVector2i ruru_convert_2u_to_2i(sfVector2u convert)
{
    sfVector2i vector = {(int) convert.x, (int) convert.y};
    return vector;
}
