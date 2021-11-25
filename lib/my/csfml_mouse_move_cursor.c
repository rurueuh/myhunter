/*
** EPITECH PROJECT, 2021
** be able the cursor follow you crosshair
** File description:
** need window, and sprite of cursor (use create_cursor)
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfSprite* ruru_mouse_move_cursor(sfRenderWindow* window, sfSprite* sprite)
{
    int w = sfSprite_getLocalBounds(sprite).width;
    int h = sfSprite_getLocalBounds(sprite).height;
    sfVector2i m = sfMouse_getPositionRenderWindow(window);
    sfVector2f vector_mousef = {(float) m.x - w / 2, (float) m.y - h / 2};
    sfSprite_setPosition(sprite, vector_mousef);
    return sprite;
}
