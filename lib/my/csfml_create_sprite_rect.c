/*
** EPITECH PROJECT, 2021
** create sprite
** File description:
** need path, for position X && y , need Int rect (no null if null delete _r)
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfSprite* ruru_create_sprite_r(char *path, int pos_x, int pos_y, sfIntRect r)
{
    sfSprite* sprinte = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprinte, texture, sfTrue);
    sfSprite_setTextureRect(sprinte, r);
    sfVector2f pos = {(float) pos_x, (float) pos_y};
    sfSprite_setPosition(sprinte, pos);
    return sprinte;
}
