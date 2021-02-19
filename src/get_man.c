/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** get_man
*/

#include "../include/sokoban.h"

void get_man(void)
{
    my_putstr("USAGE:\n");
    my_putstr("\t./my_sokoban [map]\n");
    my_putstr("DESCRIPTION:\n");
    my_putstr("\tmap file representing the warehouse map, \
    containing ‘#’ for walls, \n");
    my_putstr("\t‘P’ for the player, ‘X’ for boxes and ‘O’ \
    for storage locations.\n");
    exit (0);
}