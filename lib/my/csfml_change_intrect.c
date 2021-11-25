/*
** EPITECH PROJECT, 2021
** create Int rect
** File description:
** need X Y width height
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfIntRect ruru_change_intrect(sfIntRect rect, int offset_x, int offset_y)
{
    rect.left += offset_x;
    rect.top += offset_y;
    return rect;
}
