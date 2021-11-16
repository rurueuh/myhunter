/*
** EPITECH PROJECT, 2021
** window
** File description:
** just one window
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
sfSprite* ressource_scope(void);
sfSprite* ressource_stage(sfVector2u size);
sfSprite* ressource_duck(void);
sfRenderWindow* create_window(void);
void move_duck(global ruru);
void cloak_5_recreate_duck(global ruru);

global fill_struct(void)
{
    global ruru;
    ruru.window = create_window();
    ruru.size = sfRenderWindow_getSize(ruru.window);
    ruru.sprite_scope = ressource_scope();
    ruru.sprite_stage = ressource_stage(ruru.size);
    ruru.sprite_duck = ressource_duck();
    ruru.vec_sprite_duck = sfSprite_getPosition(ruru.sprite_duck);
    ruru.x = sfFalse;
    ruru.y = sfFalse;
    ruru.score = 0;
    return ruru;
}

void event_close(sfRenderWindow *window,sfEvent event)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape) ){
        sfRenderWindow_close(window);
    }
}

void draw_sprite(sfRenderWindow *window, sfSprite* sprite_scope, sfSprite* map,
sfSprite* sprite_duck)
{
    sfRenderWindow_clear(window,sfBlack);
    sfRenderWindow_drawSprite(window, map, NULL);
    sfRenderWindow_drawSprite(window, sprite_duck, NULL);
    sfRenderWindow_drawSprite(window, sprite_scope, NULL);
    sfRenderWindow_display(window);
}
// todo mouvement pigeon
void move_duck_calc(global ruru)
{
    if (ruru.vec_sprite_duck.x > 1920)
        ruru.x = sfTrue;
    if (ruru.vec_sprite_duck.x < 0)
        ruru.x = sfFalse;
    if (ruru.vec_sprite_duck.y > 800)
        ruru.y = sfTrue;
    if (ruru.vec_sprite_duck.y < 0)
        ruru.y = sfFalse;
    move_duck(ruru);
}

global shoot(global ruru)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)){
        sfVector2f vector_duck = sfSprite_getPosition(ruru.sprite_duck);
        sfVector2i vector_mouse = sfMouse_getPositionRenderWindow(ruru.window);
        sfVector2f vector_reset_duck = {100, 700};
        if (ruru.x == sfFalse){
            if (vector_mouse.x < vector_duck.x + 26 * 4
            && vector_mouse.x >= vector_duck.x
            && vector_mouse.y < vector_duck.y + 18 * 4
            && vector_mouse.y >= vector_duck.y){
                sfSprite_setPosition(ruru.sprite_duck, vector_reset_duck);
                cloak_5_recreate_duck(ruru);
            }
        } else {
            if (vector_mouse.x < vector_duck.x
            && vector_mouse.x >= vector_duck.x - 26 * 4
            && vector_mouse.y < vector_duck.y + 18 * 4
            && vector_mouse.y >= vector_duck.y){
                sfSprite_setPosition(ruru.sprite_duck, vector_reset_duck);
                cloak_5_recreate_duck(ruru);
            }
        }
    }
    return ruru;
}

void game(void)
{
    global ruru = fill_struct();
    while (sfRenderWindow_isOpen(ruru.window)){
        ruru.vec_sprite_duck = sfSprite_getPosition(ruru.sprite_duck);
        while (sfRenderWindow_pollEvent(ruru.window, &ruru.event)){
            ruru.sprite_scope = mouse_scope(ruru.window, ruru.sprite_scope);
            event_close(ruru.window, ruru.event);
            ruru = shoot(ruru);
        }
        if (ruru.vec_sprite_duck.x > 1920)
            ruru.x = sfTrue;
        if (ruru.vec_sprite_duck.x < 0)
            ruru.x = sfFalse;
        if (ruru.vec_sprite_duck.y > 800)
            ruru.y = sfTrue;
        if (ruru.vec_sprite_duck.y < 0)
            ruru.y = sfFalse;
        move_duck(ruru);
        draw_sprite(ruru.window, ruru.sprite_scope, ruru.sprite_stage,
        ruru.sprite_duck);
    }
}
