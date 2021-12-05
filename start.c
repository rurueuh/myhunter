/*
** EPITECH PROJECT, 2021
** start
** File description:
** start of game
*/

#include "include/my.h"
#include <stdio.h>
#include <time.h>

void game(void);

int main(int ac, char **av)
{
    if (ac == 1){
        srand(time(NULL));
        game();
        return 0;
    }
    if (av[1][0] == '-'){
        if (av[1][1] == 'h'){
            my_putstr("welcome to my first game rule:\n");
            my_putstr("-a duck will move in the screen try to shoot him\n");
            my_putstr("-your score in on the left buttom\n");
            my_putstr("-have fun ! echap for leave\n");
            return 0;
        }
    } else {
        return 1;
    }
}
