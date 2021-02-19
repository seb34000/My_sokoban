/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_sokoban
*/

#include "../include/sokoban.h"
#include "../include/stuct.h"

void reset(soko_t *game)
{
    for (int i = 0; game->map[i]; i++) {
        game->map[i] = my_strdup(game->map_save[i]);
    }
    game->player.x = game->player.orgx;
    game->player.y = game->player.orgy;
    move(game->player.orgx, game->player.orgy);
}

void get_key(soko_t *game)
{
    int key = getch();
    switch (key) {
        case KEY_UP:
            move_up(game);
            break;
        case KEY_DOWN:
            move_down(game);
            break;
        case KEY_LEFT:
            move_left(game);
            break;
        case KEY_RIGHT:
            move_right(game);
            break;
        case KEY_SPACE:
            reset(game);
            break;
    }
}

void game_loop(soko_t *game)
{
    int key = 0;
    bool games = true;

    while (games == true) {
        if (tcheck_size(game) == true) {
            win_or_loose(game);
            print_map(game);
            get_key(game);
        } else {
            is_good_size(game);
        }
    }
}

void sokoban(soko_t *game)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    print_map(game);
    move(game->player.x, game->player.y);
    refresh();
    game_loop(game);
    getch();
    endwin();
}