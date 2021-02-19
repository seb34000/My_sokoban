/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** tcheck_win
*/

#include "../include/sokoban.h"
#include "../include/stuct.h"

void tcheck_win(soko_t *game)
{
    size_t test = 0;

    for (int i = 0; game->map[i]; i++) {
        for (int j = 0; game->map[i][j]; j++) {
            test += \
            (game->map_save[i][j] == 'O' && game->map[i][j] == 'X') ? 1 : 0;
        }
    }
    if (test == game->init->box && test == game->init->storage) {
        endwin();
        free_map(game);
        exit (0);
    }
}

bool tcheck_loose_v2(soko_t *game, int i, int j, size_t test)
{
    if ((game->map[i][j] == 'X') && (game->map_save[i][j] != 'O') \
    && ((game->map[i + 1][j] == '#' && game->map[i][j + 1] == '#') \
    || (game->map[i + 1][j] == '#' && game->map[i][j - 1] == '#') \
    || (game->map[i - 1][j] == '#' && game->map[i][j - 1] == '#') \
    || (game->map[i - 1][j] == '#' && game->map[i][j + 1] == '#'))) {
        return (true);
    }
    return (false);
}

void tcheck_loose(soko_t *game)
{
    size_t test = 0;

    for (int i = 0; game->map[i]; i++) {
        for (int j = 0; game->map[i][j]; j++) {
            test += (tcheck_loose_v2(game, i, j, test) == true) ? 1 : 0;
        }
    }
    if (test == game->init->box) {
        endwin();
        free_map(game);
        exit (1);
    }
}

void win_or_loose(soko_t *game)
{
    tcheck_win(game);
    tcheck_loose(game);
}