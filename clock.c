/*
** EPITECH PROJECT, 2021
** clock
** File description:
** speed of the game
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

sfSprite* mouse_scope(sfRenderWindow *window, sfSprite* sprinte_scope);
void func(void);

sfSprite* ressource_dog(void)
{
    sfVector2f scale = {5, 5};
    sfVector2f pos = {850, 650};
    sfSprite* sprinte_stage = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile("michel/dog1.png", NULL);
    sfSprite_setScale(sprinte_stage, scale);
    sfSprite_setPosition(sprinte_stage, pos);
    sfSprite_setTexture(sprinte_stage, texture, sfTrue);
    return sprinte_stage;
}

void draw_cloak(sfRenderWindow *window, sfSprite* sprite_scope, sfSprite* map,
sfSprite* sprite_dog)
{
    sfRenderWindow_clear(window,sfBlack);
    sfRenderWindow_drawSprite(window, map, NULL);
    sfRenderWindow_drawSprite(window, sprite_dog, NULL);
    sfRenderWindow_drawSprite(window, sprite_scope, NULL);
    sfRenderWindow_display(window);
}

sfTexture* switch_texture_dog(float seconds, float i,
sfSprite* dog, sfTexture* texture)
{
    if (seconds > 1.0){
        texture = sfTexture_createFromFile("michel/dog1.png", NULL);
    }
    if (seconds > 1.5){
        texture = sfTexture_createFromFile("michel/dog2.png", NULL);
    }
    if (seconds > 2.0){
        texture = sfTexture_createFromFile("michel/dog1.png", NULL);
    }
    return texture;
}

global cloak_5_recreate_duck(global ruru)
{
    sfClock *clock;
    sfTime time;
    sfSprite* dog = ressource_dog();
    sfTexture* texture = sfTexture_createFromFile("michel/dog1.png", NULL);
    float seconds;
    float i = 0.0;
    clock = sfClock_create();
    while (1){
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        texture = switch_texture_dog(seconds, i, dog, texture);
        sfSprite_setTexture(dog, texture, sfTrue);
        if (seconds > 3.0){
            sfSprite_destroy(dog);
            return ruru;
        }
        ruru.sprite_scope = mouse_scope(ruru.window, ruru.sprite_scope);
        draw_cloak(ruru.window, ruru.sprite_scope, ruru.sprite_stage, dog);
    }
}

global clock_move(global ruru)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;
    while (1){
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.2){
        }
    }
}