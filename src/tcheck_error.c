/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** tcheck_error
*/

#include "../include/sokoban.h"
#include "../include/stuct.h"

bool test_map(char c)
{
    if (c == ' ' || c == '\n' || c == '#' || c == 'X' || c == 'O' || c == 'P')
        return (true);
    else {
        my_putstr("Error: Map not correct see -h for mor information\n");
        exit(84);
    }
}

int tcheck_map(soko_t *game)
{
    for (size_t i = 0; i < my_ptrlen(game->map); i++) {
        for (size_t j = 0; j < my_strlen(game->map[i]); j++) {
            (game->map[i][j] == 'P') ? init_player(game, i, j) : NULL;
            (game->map[i][j] == 'X') ? init_box(game, i, j) : NULL;
            (game->map[i][j] == '#') ? init_wall(game, i, j) : NULL;
            (game->map[i][j] == 'O') ? init_storage(game, i, j) : NULL;
            test_map(game->map[i][j]);
        }
    }
    return (0);
}

bool tcheck_size(soko_t *game)
{
    int y_max = 0;
    int x_max = 0;
    int cols = my_strlen(game->map[0]);
    int line = my_ptrlen(game->map);

    getmaxyx(stdscr, y_max, x_max);
    if (y_max < cols || x_max < line - 1) {
        return (false);
    }
    return (true);
}

void tcheck_ox(void)
{
    my_putstr("Error:  number of box has different from the number \
    of storage space\n");
    exit(84);
}

void is_good_size(soko_t *game)
{
    char *msg = "Error: Your terminal it's to small, please expend it";

    while (tcheck_size(game) == false) {
        clear();
        mvprintw(LINES/2, (COLS / 2) - (my_strlen(msg) / 2), msg);
        refresh();
    }
}