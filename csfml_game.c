/*
** EPITECH PROJECT, 2021
** create window
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/mycsfml.h"
#include "include/my.h"
#include "include/mygame.h"
#include "include/mystruct.h"

void draw_sprite(sfRenderWindow* window, stuct_sprite sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite.map, NULL);
    sfRenderWindow_drawSprite(window, sprite.duck, NULL);
    sfRenderWindow_drawSprite(window, sprite.mouse, NULL);
    //sfRenderWindow_drawText(window, sprite.score, NULL);
    sfRenderWindow_display(window);
}

int game(void)
{
    sfRenderWindow* window = ruru_create_window(1920, 1080, 144, sfFalse);
    sfEvent event;
    stuct_wall wall = ressource_wall();
    stuct_rect rect = ressource_rect();
    stuct_sprite sprite = ressource_sprite(rect, window);
    stuct_anim_duck clock = ressource_anim_duck();
    if (startscreen(window, event) == 1)
        return 0;
    while (sfRenderWindow_isOpen(window)){
        while (sfRenderWindow_pollEvent(window, &event)){
            ruru_event_close(window, event);
            wall = click_duck(window, sprite, rect, wall);
            //sprite.score = ruru_create_text(10, 10, my_int_to_str(3), 18);
        }
        wall = move_duck(window, sprite.duck, wall);
        ruru_anim_3_frames(clock, sprite.duck, 0.3);
        
        draw_sprite(window, sprite);
    }
    return 0;
}
