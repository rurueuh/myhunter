/*
** EPITECH PROJECT, 2021
** int to str
** File description:
** change a int to str
*/

#include <stdlib.h>
#include <unistd.h>

char *my_revstr(char *str);

char *my_int_to_str(int a)
{
    int i = 1;
    int size = a;
    while (size / 10 != 0){
        size = size / 10;
        i++;
    }
    char *result = malloc(i);
    for (int k = 0; k < i; k++){
        result[k] = a % 10 + '0';
        a /= 10;
    }
    my_revstr(result);
    return result;
}
