/*
** EPITECH PROJECT, 2021
** create window
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

void ruru_scale_sprite(sfSprite* sprite, float scale_x, float scale_y)
{
    sfVector2f scale = {(float) scale_x, (float) scale_y};
    sfSprite_setScale(sprite, scale);
}
