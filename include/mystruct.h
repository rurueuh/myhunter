/*
** EPITECH PROJECT, 2021
** my header
** File description:
** my
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#ifndef csfml_struct
    #define csfml_struct
    
    typedef struct stuct_sprite {
        sfSprite* duck;
        sfSprite* dog;
        sfSprite* mouse;
        sfSprite* map;
        sfText* score;
    } stuct_sprite;

    typedef struct stuct_sound {

    } stuct_sound;

    typedef struct stuct_wall {
        sfBool x_wall;
        sfBool y_wall;
        int score;

    } stuct_wall;

    typedef struct stuct_rect {
        sfIntRect duck;
        sfIntRect dog;
    } stuct_rect;

    typedef struct stuct_anim_duck {
        sfTime time;
        sfIntRect duck_anim1;
        sfIntRect duck_anim2;
        sfIntRect duck_anim3;
        sfClock* clock;
    } stuct_anim_duck;

    typedef struct stuct_vector {
        sfVector2f ruru;
    } stuct_vector;

    typedef struct stuct_scale {
        sfVector2f duck;
        sfVector2f dog;
    } stuct_scale;

#endif