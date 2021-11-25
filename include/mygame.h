/*
** EPITECH PROJECT, 2021
** my header
** File description:
** my
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "./mystruct.h"

#ifndef header_game
    #define header_game
    int startscreen(sfRenderWindow* window, sfEvent event);
    stuct_sprite ressource_sprite(sfRenderWindow* window);
    stuct_rect ressource_rect(void);
    stuct_scale ressource_scale(sfRenderWindow* window, stuct_sprite sprite);
#endif