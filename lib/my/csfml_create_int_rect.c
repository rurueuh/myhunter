/*
** EPITECH PROJECT, 2021
** create Int rect
** File description:
** need X Y width height
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfIntRect ruru_create_intrect(int left, int top, int width, int height)
{
    sfIntRect test;
    test.top = top;
    test.left = left;
    test.width = width;
    test.height = height;
    return test;
}
