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
#include "include/mygame.h"
#include "include/mystruct.h"

void draw_sprite_dog(sfRenderWindow* window, stuct_sprite sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite.map, NULL);
    sfRenderWindow_drawSprite(window, sprite.dog, NULL);
    sfRenderWindow_drawSprite(window, sprite.mouse, NULL);
    sfRenderWindow_display(window);
}

void draw_dog(sfRenderWindow* window ,stuct_sprite sprite)
{
    sfClock *clock = sfClock_create();
    sfIntRect dog_anim;
    while (1){
        sfTime time = sfClock_getElapsedTime(clock);
        float seconds = time.microseconds / 1000000.0;
        if (seconds >= 0)
            dog_anim = ruru_create_intrect(248, 2 , 32, 30);
        if (seconds >= 1)
            dog_anim = ruru_create_intrect(191, 47 , 23, 29);
        if (seconds >= 1.4)
            dog_anim = ruru_create_intrect(146, 47 , 23, 29);
        if (seconds >= 1.8)
            dog_anim = ruru_create_intrect(191, 47 , 23, 29);
        if (seconds >= 2.2)
            return;
        sprite.dog = ruru_create_sprite_r("michel/sheet.png", 850,
        650, dog_anim);
        ruru_mouse_move_cursor(window, sprite.mouse);
        ruru_scale_sprite(sprite.dog, 8, 8);
        draw_sprite_dog(window, sprite);
    }
}

stuct_wall click_duck(sfRenderWindow* window, stuct_sprite sprite,
stuct_rect rect, stuct_wall wall)
{
    ruru_mouse_move_cursor(window, sprite.mouse);
    if (ruru_mouse_touch_sprite(window, sprite.duck) == sfTrue){
        sfSprite_destroy(sprite.duck);
        sprite.duck = ruru_create_sprite_r("michel/sheet.png", 100,
        100, rect.duck);
        draw_dog(window, sprite);
        ruru_scale_sprite(sprite.duck, 4, 4);
        wall.x_wall = sfFalse;
        wall.y_wall = sfFalse;
        wall.score++;
    }
    return wall;
}

stuct_wall duck_wall(sfRenderWindow* window, sfSprite* duck, stuct_wall wall)
{
    sfVector2f pos = sfSprite_getPosition(duck);
    if (pos.x >= 1920){
        wall.x_wall = sfTrue;
        ruru_scale_sprite(duck, -4, 4);
    }
    if (pos.x <= 0){
        wall.x_wall = sfFalse;
        ruru_scale_sprite(duck, 4, 4);
    }
    if (pos.y >= 720){
        wall.y_wall = sfTrue;
    }
    if (pos.y <= 0){
        wall.y_wall = sfFalse;
    }
    return wall;
}

stuct_wall move_duck(sfRenderWindow* window, sfSprite* duck, stuct_wall wall)
{
    int speed = 2;
    sfVector2f x_left = {speed, 0};
    sfVector2f x_right = {-speed, 0};
    sfVector2f y_down = {0, speed};
    sfVector2f y_up = {0, -speed};
    sfVector2f pos_duck = sfSprite_getPosition(duck);
    if (wall.x_wall == sfFalse)
        sfSprite_move(duck, x_left);
    else
        sfSprite_move(duck, x_right);
    if (wall.y_wall == sfFalse)
        sfSprite_move(duck, y_down);
    else
        sfSprite_move(duck, y_up);
    wall = duck_wall(window, duck, wall);
    return wall;
}
