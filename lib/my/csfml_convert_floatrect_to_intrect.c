/*
** EPITECH PROJECT, 2021
** create window
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfIntRect ruru_convert_floatrect_to_intrect(sfFloatRect intrect)
{
    sfIntRect convert;
    convert.top = (int) intrect.top;
    convert.left = (int) intrect.left;
    convert.width = (int) intrect.width;
    convert.height = (int) intrect.height;
    return convert;
}
