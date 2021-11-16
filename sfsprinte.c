/*
** EPITECH PROJECT, 2021
** sprinte
** File description:
** sprinte
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/my.h"

sfRenderWindow* create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 1};
    window = sfRenderWindow_create(video_mode, "<3",
    sfResize | sfClose, 0);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 120);
    return window;
}

sfSprite* mouse_scope(sfRenderWindow *window, sfSprite* sprinte_scope)
{
    int w = 25;
    int h = 25;
    sfVector2i m = sfMouse_getPositionRenderWindow(window);
    sfVector2f vector_mousef = {(float) m.x - w / 2, (float) m.y - h / 2};
    sfSprite_setPosition(sprinte_scope, vector_mousef);
    return sprinte_scope;
}

sfSprite* ressource_scope(void)
{
    sfSprite* sprinte_stage = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile("michel/scope.png", NULL);
    sfSprite_setTexture(sprinte_stage, texture, sfTrue);
    return sprinte_stage;
}

sfSprite* ressource_stage(sfVector2u size)
{
    float x_scale = (float) size.x / 1280.0;
    float y_scale = (float) size.y / 769.0;
    sfVector2f scale = {x_scale, y_scale};
    sfSprite* sprinte_stage = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile("michel/stage.png", NULL);
    sfSprite_setScale(sprinte_stage, scale);
    sfSprite_setTexture(sprinte_stage, texture, sfTrue);
    return sprinte_stage;
}

sfSprite* ressource_duck()
{
    float difficulty = 3.5;
    sfVector2f scale = {difficulty, difficulty};

    sfSprite* sprinte_stage = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile("michel/blue_1.png", NULL);
    sfSprite_setScale(sprinte_stage, scale);
    sfSprite_setPosition(sprinte_stage, scale);
    sfSprite_setTexture(sprinte_stage, texture, sfTrue);
    return sprinte_stage;
}
