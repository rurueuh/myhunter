/*
** EPITECH PROJECT, 2021
** my header
** File description:
** my
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "mystruct.h"

#ifndef header_graph
    #define header_graph
    sfRenderWindow* ruru_create_window(int width, int height, int fps,
    sfBool fullscreen);
    sfSprite* ruru_create_sprite_r(char *path, int pos_x, int pos_y,
    sfIntRect r);
    sfSprite* ruru_create_sprite(char *path, int pos_x, int pos_y);
    sfText* ruru_create_text(int pos_x, int pos_y, char *str, int police_size);
    sfIntRect ruru_create_intrect(int left, int top, int width, int height);
    sfVector2u ruru_create_vector2u(unsigned int x, unsigned int y);
    sfVector2i ruru_create_vector2i(int x, int y);
    sfVector2f ruru_create_vector2f(float x, float y);

    void ruru_anim_3_frames(stuct_anim_duck clock, sfSprite* sprite,
    float sec);

    sfBool ruru_mouse_touch_sprite(sfRenderWindow* window, sfSprite* sprite);
    sfSprite* ruru_mouse_move_cursor(sfRenderWindow* window, sfSprite* sprite);
    sfSprite* ruru_create_cursor(sfRenderWindow* window, char *path);

    void ruru_draw_sprite(sfRenderWindow* window, int nombre_de_sprite, ...);
    
    void ruru_scale_sprite(sfSprite* sprite, float scale_x, float scale_y);
    void ruru_scale_fullscreen(sfRenderWindow* window, sfSprite* sprite);

    sfFloatRect ruru_convert_intrect_to_floatrect(sfIntRect intrect);
    sfIntRect ruru_convert_floatrect_to_intrect(sfFloatRect intrect);
    sfVector2i ruru_convert_2f_to_2i(sfVector2f convert);
    sfVector2u ruru_convert_2f_to_2u(sfVector2f convert);
    sfVector2f ruru_convert_2u_to_2f(sfVector2u convert);
    sfVector2i ruru_convert_2u_to_2i(sfVector2u convert);
    sfVector2f ruru_convert_2i_to_2f(sfVector2i convert);
    sfVector2u ruru_convert_2i_to_2u(sfVector2i convert);
    void ruru_event_close(sfRenderWindow* window, sfEvent event);
#endif