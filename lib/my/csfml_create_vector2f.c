/*
** EPITECH PROJECT, 2021
** create vector2f
** File description:
** create vector2f
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfVector2f ruru_create_vector2f(float x, float y)
{
    sfVector2f vector = {x, y};
    return vector;
}

sfVector2u ruru_create_vector2u(unsigned int x, unsigned int y)
{
    sfVector2u vector = {x, y};
    return vector;
}

sfVector2i ruru_create_vector2i(int x, int y)
{
    sfVector2i vector = {x, y};
    return vector;
}
