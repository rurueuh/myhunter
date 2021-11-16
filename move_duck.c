/*
** EPITECH PROJECT, 2021
** move duck
** File description:
** gestion of moving duck
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/my.h"

typedef struct ruru {
    sfRenderWindow* window;
    sfEvent event;
    sfVector2u size;
    sfSprite* sprite_scope ;
    sfSprite* sprite_stage;
    sfSprite* sprite_duck;
    sfBool x;
    sfBool y;
    sfVector2f vec_sprite_duck;
    int score;
} global;

void move_duck(global ruru)
{
    int speed = 2;
    sfVector2f offset_x_pos = {speed, 0};
    sfVector2f offset_x_neg = {-speed, 0};
    sfVector2f offset_y_pos = {0, speed};
    sfVector2f offset_y_neg = {0, -speed};
    sfVector2f flip_sprite = {-4, 4};
    sfVector2f unflip_sprite = {4, 4};
    if (ruru.x == sfFalse){
        sfSprite_move(ruru.sprite_duck, offset_x_pos);
        sfSprite_setScale(ruru.sprite_duck, unflip_sprite);
    }
    if (ruru.x == sfTrue){
        sfSprite_move(ruru.sprite_duck, offset_x_neg);
        sfSprite_setScale(ruru.sprite_duck, flip_sprite);
    }
    if (ruru.y == sfFalse){
        sfSprite_move(ruru.sprite_duck, offset_y_pos);
    }
    if (ruru.y == sfTrue){
        sfSprite_move(ruru.sprite_duck, offset_y_neg);
    }
}