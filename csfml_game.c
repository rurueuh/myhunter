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
#include <stdlib.h>

void event_shoot(sfRenderWindow* window, stuct_sprite sprite, sfEvent event)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)){
        if (ruru_mouse_touch_sprite(window, sprite.duck) == sfTrue){
            sfVector2f test = {rand() % 1921, 0};
            sfSprite_setPosition(sprite.duck, test);
        }
    }
}

stuct_wall duck_wall(sfRenderWindow* window, sfSprite* duck, stuct_wall wall)
{
    sfVector2f pos = sfSprite_getPosition(duck);
    if (pos.x >= 1920){
        wall.x_wall = sfTrue;
        ruru_scale_sprite(duck, -1, 1);
    }
    if (pos.x <= 0){
        wall.x_wall = sfFalse;
        ruru_scale_sprite(duck, -1, 1);
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
    int speed = 5;
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

void main(void)
{
    sfRenderWindow* window = ruru_create_window(1920, 1080, 144, sfTrue);
    stuct_sprite ruru = ressource_sprite(window);
    stuct_wall wall;
    sfClock *clock = sfClock_create();
    sfEvent event;
    if (startscreen(window, event) == 1)
        return;
    while (sfRenderWindow_isOpen(window)){
        sfTime time = sfClock_getElapsedTime(clock);
        float seconds = time.microseconds / 1000000.0;
        while (sfRenderWindow_pollEvent(window, &event)){
            ruru_event_close(window, event);
            ruru_mouse_move_cursor(window, ruru.mouse);
            event_shoot(window, ruru, event);
        }
        if (seconds >= 0.01){
            wall = move_duck(window, ruru.duck, wall);
            sfClock_restart(clock);
        }
        ruru_draw_sprite(window, 3, ruru.stage, ruru.duck, ruru.mouse);
    }
}
