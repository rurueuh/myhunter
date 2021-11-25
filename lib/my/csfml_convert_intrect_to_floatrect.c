/*
** EPITECH PROJECT, 2021
** create window
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfFloatRect ruru_convert_intrect_to_floatrect(sfIntRect intrect)
{
    sfFloatRect convert;
    convert.top = (float) intrect.top;
    convert.left = (float) intrect.left;
    convert.width = (float) intrect.width;
    convert.height = (float) intrect.height;
    return convert;
}
