/*
** EPITECH PROJECT, 2021
** create window
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include "include/mycsfml.h"
#include "include/my.h"
#include "include/mystruct.h"

stuct_rect ressource_rect(void)
{
    stuct_rect rect;
    rect.dog = ruru_create_intrect(147, 47, 22, 29);
    rect.duck = ruru_create_intrect(0, 90, 26, 18);
    return rect;
};

stuct_scale ressource_scale(sfRenderWindow* window, stuct_sprite sprite)
{
    stuct_scale scale;

    sfVector2f dog = {8, 8};
    sfVector2f duck = {5, 5};
    scale.duck = duck;
    scale.dog = dog;
    sfSprite_scale(sprite.duck, duck);
    sfSprite_scale(sprite.dog, dog);

    return scale;
};

stuct_sprite ressource_sprite(sfRenderWindow* window)
{
    stuct_sprite sprite;
    stuct_rect rect = ressource_rect();

    sprite.dog = ruru_create_sprite_r("michel/sheet.png", 0, 0, rect.dog);
    sprite.duck = ruru_create_sprite_r("michel/sheet.png", 0, 0, rect.duck);
    sprite.stage = ruru_create_sprite("michel/stage.png", 0, 0);
    ruru_scale_fullscreen(window, sprite.stage);
    sprite.mouse = ruru_create_cursor(window, "michel/scope.png");

    ressource_scale(window, sprite);
    return sprite;
};
