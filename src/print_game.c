/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** print_game
*/

#include "../include/sokoban.h"
#include "../include/stuct.h"

void actualise_map(soko_t *game, int i, int j)
{
    if (game->map_save[i][j] == 'O' \
    && game->map[i][j] != 'O' \
    && game->map[i][j] != 'P' \
    && game->map[i][j] != 'X')
        game->map[i][j] = 'O';
}

void print_map(soko_t *game)
{
    erase();
    for (int i = 0; game->map[i]; i++) {
        for (int j = 0; game->map[i][j]; j++) {
            actualise_map(game, i, j);
        }
    }
    for (int i = 0; game->map[i]; i++) {
        printw("%s\n", game->map[i]);
    }
    move(game->player.x, game->player.y);
    refresh();
}