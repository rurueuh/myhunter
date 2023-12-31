/*
** EPITECH PROJECT, 2021
** create window
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

void ruru_scale_fullscreen(sfRenderWindow* window, sfSprite* sprite)
{
    sfFloatRect size_sprite = sfSprite_getLocalBounds(sprite);
    sfVector2u size_window = sfRenderWindow_getSize(window);
    float x_scale = (float) size_window.x / size_sprite.width;
    float y_scale = (float) size_window.y / size_sprite.height;
    sfVector2f scale = {x_scale, y_scale};
    sfSprite_setScale(sprite, scale);
}
