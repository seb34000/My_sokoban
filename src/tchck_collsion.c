/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** tchck_collsion
*/

#include "../include/sokoban.h"
#include "../include/stuct.h"

int test_move(soko_t *game, int x, int y)
{
    switch (game->map[x][y]) {
        case ' ':
            return (0);
        case 'X':
            return (1);
        case 'O':
            return (2);
        case '#':
            return (3);
    }
}