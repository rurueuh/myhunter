/*
** EPITECH PROJECT, 2021
** create window
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfSprite* ruru_create_sprite(char *path, int pos_x, int pos_y)
{
    sfSprite* sprinte = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprinte, texture, sfTrue);
    sfVector2f pos = {(float) pos_x, (float) pos_y};
    sfSprite_setPosition(sprinte, pos);
    return sprinte;
}
