/*
** EPITECH PROJECT, 2021
** create window
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfVector2f ruru_convert_2u_to_2f(sfVector2u convert)
{
    sfVector2f vector = {(float) convert.x, (float) convert.y};
    return vector;
}
