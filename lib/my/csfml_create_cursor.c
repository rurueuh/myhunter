/*
** EPITECH PROJECT, 2021
** create cursor
** File description:
** remove window cursor, need window, path
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfSprite* ruru_create_cursor(sfRenderWindow* window, char *path)
{
    sfSprite* sprinte = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprinte, texture, sfTrue);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return sprinte;
}
