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

int ruru_menu_close_game(sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) ){
        return 1;
    } else {
        return 0;
    }
}

int move_selector(sfText* selector, sfRenderWindow* window, sfEvent event)
{
    sfVector2i pos = ruru_convert_2f_to_2i(sfText_getPosition(selector));
    if (sfKeyboard_isKeyPressed(sfKeyUp)){
        sfVector2f move = {0, -100};
        if (pos.y - 100 < 600)
            return 0;
        sfText_move(selector, move);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)){
        sfVector2f move = {0, 100};
        if (pos.y + 100 > 700)
            return 0;
        sfText_move(selector, move);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter)){
        if (pos.y == 600)
            return 2;
        if (pos.y == 700)
            return 1;
        return 84;
    }
    return 0;
}

int startscreen_select(sfRenderWindow* window, sfEvent event, sfText* selector,
sfSprite* menu)
{
    sfText* option1 = ruru_create_text(800, 600, "- PLAY !", 60);
    sfText* option2 = ruru_create_text(800, 700, "- QUIT !", 60);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, selector, NULL);
    sfRenderWindow_drawText(window, option1, NULL);
    sfRenderWindow_drawText(window, option2, NULL);
    sfRenderWindow_drawSprite(window, menu, NULL);
    sfRenderWindow_display(window);
    sfText_destroy(option2);
    sfText_destroy(option1);
    return 0;
}

int startscreen(sfRenderWindow* window, sfEvent event)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;
    int exit = 0;
    sfText* selector = ruru_create_text(700, 600, ">", 60);
    sfIntRect rect_title = ruru_create_intrect(0, 0, 678, 272);
    sfSprite* t = ruru_create_sprite_r("michel/l.png", 600, 200, rect_title);
    while (1){
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        while (sfRenderWindow_pollEvent(window, &event)){
            exit = ruru_menu_close_game(event);
            exit = move_selector(selector, window, event);
        }
        if (exit == 1)
            return 1;
        if (seconds > 20.0 || sfKeyboard_isKeyPressed(sfKeySpace) || exit == 2)
            return 0;
        exit = startscreen_select(window, event, selector, t);
    }
}
